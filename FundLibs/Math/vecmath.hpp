#ifndef __VEC_MATH_HPP__
#define __VEC_MATH_HPP__
#include <cstdint>
#include <cassert>
#include <cstdarg>

typedef uint32_t num_int;

#define temp_vec_def template <typename T, num_int DIM, typename elip_type = T>
#define temp_vec_def_u template <typename T, num_int DIM, typename U, typename elip_type = T>
#define vec_def vec<T, DIM, elip_type>

#define sum(i, dim, operation) for(num_int i(dim);i--;operation)
#define sumS(i, start, end, operation) for(num_int i(end);(i--)-start;operation)

temp_vec_def
class vec {
private:
	T _data[DIM];
public:
	vec() {}
	vec(T n) { sum(i, DIM, _data[i] = n); }
	template <typename D, typename elip_>
	vec(vec<D, DIM, elip_> v) { sum(i, DIM, _data[i] = (T)v[i]); }
	vec(elip_type n0, ...) { elip_type* ptr = &n0 + DIM - 1; sum(i, DIM, _data[i] = *(ptr--)); }
	const T& operator[](const num_int& i) const { assert(i < DIM); return _data[i]; }
	      T& operator[](const num_int& i)       { assert(i < DIM); return _data[i]; }
};

temp_vec_def vec_def cpy(vec_def v) { vec_def ret; sum(i, DIM, ret[i] = v[i]); return ret; }

//manhetony norm
temp_vec_def T norm(vec_def v) { T ret = T(); sum(i, DIM, ret += v[i]); return ret; }

temp_vec_def T rotate(const num_int x, const num_int y, vec_def v, float a) {
	assert(x < DIM); assert(y < DIM);
	float s = sinf(a), c = cosf(a);
	vec_def ret = cpy(v);
	ret[x] = c * v[x] - s * v[y];
	ret[y] = s * v[x] + c * v[y];
	return ret;
}

temp_vec_def vec_def operator+(vec_def l, vec_def r) { vec_def ret; sum(i, DIM, ret[i] = l[i] + r[i]); return ret; }
temp_vec_def vec_def operator-(vec_def l, vec_def r) { vec_def ret; sum(i, DIM, ret[i] = l[i] - r[i]); return ret; }
temp_vec_def vec_def operator*(vec_def l, vec_def r) { vec_def ret; sum(i, DIM, ret[i] = l[i] * r[i]); return ret; }
temp_vec_def vec_def operator/(vec_def l, vec_def r) { vec_def ret; sum(i, DIM, ret[i] = l[i] / r[i]); return ret; }

temp_vec_def_u vec_def operator*(vec_def l, U r) { vec_def ret; sum(i, DIM, ret[i] = l[i] * r); return ret; }
temp_vec_def_u vec_def operator*(U l, vec_def r) { vec_def ret; sum(i, DIM, ret[i] = l * r[i]); return ret; }
temp_vec_def_u vec_def operator/(vec_def l, U r) { vec_def ret; sum(i, DIM, ret[i] = l[i] / r); return ret; }

temp_vec_def vec_def operator-(vec_def v) { return v * T(-1); }

typedef int32_t						vec1i;
typedef double						vec1d;
typedef int8_t						vec1c;
typedef float						vec1f;

typedef vec<int32_t, 2>				vec2i;
typedef vec<double, 2>				vec2d;
typedef vec<uint8_t, 2, int32_t>	vec2c;
typedef vec<float, 2, double>		vec2f;

typedef vec<int32_t, 3>				vec3i;
typedef vec<double, 3>				vec3d;
typedef vec<int8_t, 3, int32_t>		vec3c;
typedef vec<float, 3, double>		vec3f;

typedef vec<int32_t, 4>				vec4i;
typedef vec<double, 4>				vec4d;
typedef vec<int8_t, 4, int32_t>		vec4c;
typedef vec<float, 4, double>		vec4f;

typedef vec<int32_t, 5>				vec5i;
typedef vec<double, 5>				vec5d;
typedef vec<int8_t, 5, int32_t>		vec5c;
typedef vec<float, 5, double>		vec5f;

typedef vec<uint32_t, 6>			vec6i;
typedef vec<double, 6>				vec6d;
typedef vec<int8_t, 6, int32_t>		vec6c;
typedef vec<float, 6, double>		vec6f;

#endif //__MATH_HPP__