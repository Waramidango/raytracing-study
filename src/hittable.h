#ifndef HITTABLE_H
#define HITTABLE_H

// #include "ray.h"

// レイが衝突した結果を保存する
class hit_record {
    public:
        point3 p; // 衝突した場所
        vec3 normal; // 衝突地点の法線ベクトル
        double t;
        bool front_face; // 表面から衝突したかどうか

        // outward_normal：物体本来の法線ベクトル
        // 裏面の場合、表面と同じように光の計算ができるようにひっくり返す。
        void set_face_normal(const ray& r, const vec3& outward_normal) {
            // Sets the hit record normal vector.
            // NOTE: the parameter 'outward_normal' is assumed to have unit length.

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        // オブジェクトが破棄されるときに自動で呼ばれる関数　デストラクタ
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif