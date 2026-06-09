### 解题思路
去重，合并排序作为区间，并从两边向中间压缩

### 代码

```cpp
//快速排序
// partition 划分
template <typename T>
int64_t partition__(vector<T>& arr, const int64_t& l, const int64_t& r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    int64_t j = l;
    //遍历，每碰到比 V 小的依次与左边交换
    for (int64_t i = l + 1; i <= r; i++) {
        if (arr[i] < arr[l]) {
            swap(arr[++j], arr[i]);
        }
    }
    //patition 归位
    swap(arr[l], arr[j]);
    //返回 patition 位置
    return j;
}

template <typename T>
void quickSort__(vector<T>& arr, const int64_t& l, const int64_t& r) {

    if (l > r) return;
    int64_t p = partition__(arr, l, r);     //划分
    quickSort__(arr, l, p - 1);             //递归左排
    quickSort__(arr, p + 1, r);             //递归右排
}

template <typename T>
void quickSort(vector<T>& arr, const int64_t& n) {

    quickSort__(arr, 0, n - 1);
}

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> data;
        map<int, int> s_e;
        set<int>s_data;
        set<set<int>> s_s;
        vector<vector<int>> nums_data;
        //去重
        for (auto iter_nums = nums.begin(); iter_nums != nums.end(); iter_nums++) {
            set<int>s;
            for (auto iter_nums_n = iter_nums->begin(); iter_nums_n != iter_nums->end(); iter_nums_n++) {
                s.insert(*iter_nums_n);
                s_data.insert(*iter_nums_n);
            }
            s_s.insert(s);
        }
        for (auto iter_s_s = s_s.begin(); iter_s_s != s_s.end(); iter_s_s++) {
            nums_data.emplace_back(data);
            nums_data.back().assign(iter_s_s->begin(), iter_s_s->end());
        }
        data.assign(s_data.begin(), s_data.end());
        //排序
        quickSort(data, data.size());
        for (auto iter_data = data.begin(); iter_data != data.end(); iter_data++) {
            for (auto riter_data = data.rbegin(); riter_data != data.rend() && *riter_data >= *iter_data; riter_data++) {
                bool all_match = true;
                //遍历数组列表
                for (auto iter_nums = nums_data.begin(); iter_nums != nums_data.end(); iter_nums++) {
                    bool exist_match = false;
                    //遍历数组的数
                    for (auto iter_nums_n = iter_nums->begin(); iter_nums_n != iter_nums->end(); iter_nums_n++) {
                        if (*iter_nums_n >= *iter_data && *iter_nums_n <= *riter_data) {
                            exist_match = exist_match || true;
                            break;      //满足每个列表至少有一个数包含在其中直接跳出，减少不必要运算
                        }
                    }
                    all_match = all_match && exist_match;
                    if (all_match == false) break; //发现任一列表不满足跳出，较少不必要运算
                }
                if (all_match) {    //统计区间
                    if (s_e.find(*iter_data) == s_e.end()) {
                        s_e[*iter_data] = *riter_data;
                    }
                    else {
                        s_e[*iter_data] = min(s_e[*iter_data], *riter_data);
                    }
                }
            }
        }
        int min = s_e.begin()->second - s_e.begin()->first;
        auto min_iter = s_e.begin();
        for (auto iter_s_e = s_e.begin(); iter_s_e != s_e.end(); iter_s_e++) {
            if (min > iter_s_e->second - iter_s_e->first) {
                min = iter_s_e->second - iter_s_e->first;
                min_iter = iter_s_e;
            }
        }
        return { min_iter->first,min_iter->second };
    }

};
```