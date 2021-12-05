#include <math.h>
#include <stdio.h>
#include <vec/vec.h>

#define SIGNF(v) v > 0.0f ? 1.0f : v < 0.0f ? -1.0f : 0.0f
#define SIGNFV(v, G) v > G ? 1.0f : v < G ? -1.0f : 0.0f

Vec2 vec2_sub(Vec2 a, Vec2 b) { return VEC2_OP(a, -, b); }

Vec2 vec2_add(Vec2 a, Vec2 b) { return VEC2_OP(a, +, b); }

Vec2 vec2_div(Vec2 a, Vec2 b) { return VEC2_OP(a, /, b); }

Vec2 vec2_mul(Vec2 a, Vec2 b) { return VEC2_OP(a, *, b); }

float vec2_dot(Vec2 a, Vec2 b) { return (a.x * b.x) + (a.y * b.y); }

float vec2_length(Vec2 a) { return sqrt(pow(a.x, 2) + pow(a.y, 2)); }

Vec2 vec2_norm(Vec2 a, Vec2 b) {
  return VEC2_OP_SR(VEC2_OP(a, -, b), /, vec2_length(VEC2_OP(b, -, a)));
}

void vec2_copy(Vec2 src, Vec2 *dest) {
  dest->x = src.x;
  dest->y = src.y;
  *dest = *dest;
}

Vec3 vec3_sub(Vec3 a, Vec3 b) { return VEC3_OP(a, -, b); }

Vec3 vec3_add(Vec3 a, Vec3 b) { return VEC3_OP(a, +, b); }

Vec3 vec3_div(Vec3 a, Vec3 b) { return VEC3_OP(a, /, b); }

Vec3 vec3_mul(Vec3 a, Vec3 b) { return VEC3_OP(a, *, b); }

float vec3_dot(Vec3 a, Vec3 b) {
  return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float vec3_length(Vec3 a) {
  return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

Vec3 vec3_norm(Vec3 a, Vec3 b) {
  Vec3 norm = VEC3_OP_SR(VEC3_OP(a, -, b), /, vec3_length(VEC3_OP(b, -, a)));
  norm.x = norm.x < 0 ? -1 : norm.x == 0 ? 0 : 1;
  norm.y = norm.y < 0 ? -1 : norm.y == 0 ? 0 : 1;
  norm.y = norm.y < 0 ? -1 : norm.z == 0 ? 0 : 1;
  return norm;
}

Vec3 vec3_inv(Vec3 a) { return VEC3_OP_SR(a, *, -1); }

void vec3_copy(Vec3 src, Vec3 *dest) {
  dest->x = src.x;
  dest->y = src.y;
  dest->z = src.z;
  *dest = *dest;
}

float vec3_distance(Vec3 a, Vec3 b) {
  float deltaX = b.x - a.x;
  float deltaY = b.y - a.y;
  float deltaZ = b.z - a.z;

  return (float)sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

Vec3 vec3_uninf(Vec3 a) {
  float x = a.x;
  float y = a.y;
  float z = a.z;
  if (isinf(a.x) || isnan(a.x))
    x = 0.0f;
  if (isinf(a.y) || isnan(a.y))
    y = 0.0f;
  if (isinf(a.z) || isnan(a.z))
    z = 0.0f;

  return (Vec3){x, y, z};
}

Vec3 vec3_normalize(Vec3 a) {
  return (Vec3){SIGNF(a.x), SIGNF(a.y), SIGNF(a.z)};
}

Vec3 vec3_normalize_l(Vec3 a) {
  float length = vec3_length(a);
  float k = 1.0f / length;
  return (Vec3){a.x * k, a.y * k, a.z * k};
}

Vec3 vec3_normalize_relative(Vec3 a, Vec3 b) {
  return (Vec3){SIGNFV(a.x, b.x), SIGNFV(a.y, b.y), SIGNFV(a.z, b.z)};
}

Vec3 vec3_abs(Vec3 a) { return (Vec3){fabs(a.x), fabs(a.y), fabs(a.z)}; }

Vec3 vec3_max(Vec3 a, float v) {
  return (Vec3){fmax(a.x, v), fmax(a.y, v), fmax(a.z, v)};
}

Vec3 vec3_impulse(Vec3 dp, Vec3 n) {
  // dp = dp - n * dot(dp, n)
  return VEC3_OP(dp, -, VEC3_OP_SR(n, *, vec3_dot(dp, n)));
}

Vec3 vec3_scale(Vec3 a, float v) { return VEC3_OP_SR(a, *, v); }

unsigned int vec3_intersects(Vec3 a, Vec3 b, Vec3 b_size) {
  return ((a.x >= b.x && a.x <= b.x + b_size.x) &&
          (a.y <= b.y + b_size.y && a.y >= b.y));
}

Vec3 vec3_zero(Vec3 a, Vec3 v) {

  return (Vec3){v.x ? a.x : 0, v.y ? a.y : 0, v.z ? a.z : 0};
}

Vec3 vec3_center(Vec3 v, Vec3 s) {
  return (Vec3){v.x + s.x / 2, v.y + s.y / 2, v.z + s.z / 2};
}

Vec3 vec3_f(Vec3 a, Vec3Function f) { return (Vec3){f(a.x), f(a.y), f(a.z)}; }

float vec3_angle_between(Vec3 a, Vec3 b) {
  return atan2(a.y - b.y, a.x - b.x) * 180 /
         M_PI; // cos(vec3_dot(a, b) / (vec3_length(a)*vec3_length(b))) * 180 /
               // M_PI;
}
