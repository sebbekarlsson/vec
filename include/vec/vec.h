#ifndef VEC_H
#define VEC_H
typedef struct RAP_VECTOR2 {
  float x;
  float y;
} Vec2;

#define VEC2_OP(a, op, b) ((Vec2){ a.x op b.x, a.y op b.y })
#define VEC2_OP_SR(a, op, v) ((Vec2){ a.x op v, a.y op v })
#define VEC2_OP_SL(v, op, b) ((Vec2){ v op b.x, v op b.y })

#define VEC3_OP(a, op, b) ((Vec3){ a.x op b.x, a.y op b.y, a.z op b.z })
#define VEC3_OP_SR(a, op, v) ((Vec3){ a.x op v, a.y op v, a.z op v })
#define VEC3_OP_SR_M(a, op, v, m) ((Vec3){ fmax(a.x op v, m), fmax(a.y op v, m), fmax(a.z op v, m) })
#define VEC3_OP_SL(v, op, b) ((Vec3){ v op b.x, v op b.y, v op b.z })
#define VEC3_OP_SL_M(v, op, b, m) ((Vec3){ fmax(v op b.x, m), fmax(v op b.y, m), fmax(v op b.z, m) })

#define VEC3_ZERO() ((Vec3){0, 0, 0})

#define VEC3_PRINT(v) printf("%12.6f %12.6f %12.6f\n", v.x, v.y, v.z)

Vec2 vec2_sub(Vec2 a, Vec2 b);
float vec2_dot(Vec2 a, Vec2 b);
Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_div(Vec2 a, Vec2 b);
Vec2 vec2_mul(Vec2 a, Vec2 b);
float vec2_length(Vec2 a);
Vec2 vec2_norm(Vec2 a, Vec2 b);
void vec2_copy(Vec2 src, Vec2 *dest);



#define VEC3_VEC2(a) (Vec2){a.x, a.y}
#define VEC2_VEC3(a) (Vec3){a.x, a.y, 0.0f}

typedef struct RAP_IVECTOR2 {
  int x;
  int y;
} IVec2;

typedef struct RAP_UIVECTOR2 {
  int x;
  int y;
} UIVec2;

typedef struct RAP_VECTOR3 {
  float x;
  float y;
  float z;
} Vec3;


Vec3 vec3_sub(Vec3 a, Vec3 b);
float vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_div(Vec3 a, Vec3 b);
Vec3 vec3_mul(Vec3 a, Vec3 b);
float vec3_length(Vec3 a);
Vec3 vec3_norm(Vec3 a, Vec3 b);
void vec3_copy(Vec3 src, Vec3 *dest);

float vec3_distance(Vec3 a, Vec3 b);
Vec3 vec3_inv(Vec3 a);
Vec3 vec3_uninf(Vec3 a);
Vec3 vec3_normalize(Vec3 a);
Vec3 vec3_normalize_l(Vec3 a);
Vec3 vec3_normalize_relative(Vec3 a, Vec3 b);
Vec3 vec3_abs(Vec3 a);
Vec3 vec3_max(Vec3 a, float v);
Vec3 vec3_impulse(Vec3 dp, Vec3 n);
Vec3 vec3_zero(Vec3 a, Vec3 v);
Vec3 vec3_scale(Vec3 a, float v);
float vec3_angle_between(Vec3 a, Vec3 b);

typedef float (*Vec3Function)(float v);
Vec3 vec3_f(Vec3 a, Vec3Function f);

unsigned int vec3_intersects(Vec3 a, Vec3 b, Vec3 b_size);

Vec3 vec3_impulse(Vec3 dp, Vec3 n);

Vec3 vec3_center(Vec3 v, Vec3 s);

#endif
