#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
// #include "vec3.h"

class sphere : public hittable{
    public:
        // コンストラクタ　引数として中心座標と半径を渡す
        // std::fmax(0,radius) 0かradiusの大きいほう（半径を負の数にならないようにしている）
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(), oc); // b = -2h
            auto c = oc.length_squared() - radius*radius;

            auto discriminant = h*h - a*c; // b^2 - 4ac --> h^2 -ac
            if (discriminant < 0) // 実数解が存在しない場合
                return false;

            // (h^2 -ac)^(1/2)
            auto sqrtd = std::sqrt(discriminant);

            // Find the nearest root that lies in the acceptable range.
            auto root = (h - sqrtd) / a; //　二次方程式の解の一方（b = -2h）
            if (root <= ray_tmin || ray_tmax <= root) {
                root = (h + sqrtd) / a; //　もう一方
                if (root <= ray_tmin || ray_tmax <= root)
                    return false;
            }

            // ここまでfalseがない　--> 球とレイの交点が存在する

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif