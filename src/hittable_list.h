#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

// #include <memory>
#include <vector>

// この二つはstdをつけなくても使えるようにする
// using std::make_shared;
// using std::shared_ptr; // ポインタ

class hittable_list : public hittable {
    public:
        // hittable のポインタを格納する配列
        std::vector<shared_ptr<hittable>> objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        // 中身を全部消す
        void clear() { objects.clear(); }

        void add(shared_ptr<hittable> object) {
            // objectsの末尾に引数のobjectを追加する
            objects.push_back(object);
        }

        //　親クラス（hittable）の関数をオーバーライド
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            auto closest_so_far = ray_t.max;

            // オブジェクトの中身を順番にひとつずつ取り出す
            for (const auto& object : objects) {
                // objectのhitがtrueなら
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)){
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }
            return hit_anything;
        }
        
};

#endif