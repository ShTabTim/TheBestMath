#include <iostream>
#include "FundLibs/Math/vecmath.hpp"

int main() {
	vec3f a = vec3f(0., 3., 4.);
	std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	vec3d b = vec3d(4., 4., 2.);
	std::cout << b[0] << " " << b[1] << " " << b[2] << "\n";
	vec3d c = vec3d(a) + b;
	std::cout << c[0] << " " << c[1] << " " << c[2] << "\n";
	float e = sqrt(norm(a * a));
	std::cout << e;
}