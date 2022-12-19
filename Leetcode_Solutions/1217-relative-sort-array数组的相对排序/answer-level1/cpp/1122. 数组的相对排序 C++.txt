### 解题思路
1、自定义比较器，根据arr2的索引进行排序， 如果没有在arr2中出现过 再根据情况确定比较结果

2、统计arr1中个数字出现次数， 在按arr2中字符顺序 放入新的数组中，最后将不在arr2中的数字升序加到末尾


### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        //构建hashmap  <arr2值，arr2索引>
        unordered_map<int, int> map;
        map.reserve(arr2.size() * 2);

        for (int i = 0; i < arr2.size(); ++i)
        {
            map[arr2.at(i)] = i;
        }

        sort(arr1.begin(), arr1.end(), 
        [&](int l, int r) {
            auto iterl = map.find(l);
            auto iterr = map.find(r);
            if (iterl != map.end() && iterr != map.end()) //都存在
            {
                return iterl->second < iterr->second;
            }
            else if (iterl != map.end()) //仅l存在
            {
                return true;
            }
            else if (iterr != map.end()) //仅r存在
            {
                return false;
            }
            else
            {
                return l < r;
            }
        });

        return arr1;
    }

    //计数排序
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> res(arr1.size());

        vector<int> counts(1001);
        for (int i = 0; i < arr1.size(); ++i)
        {
            ++counts.at(arr1.at(i));
        }
        
        int k = 0;
        for (int i = 0; i < arr2.size(); ++i)
        {
            for (int j = 0; j < counts.at(arr2.at(i)); ++j)
            {
                res[k] = arr2.at(i);
                ++k;
            }
            counts.at(arr2.at(i)) = 0; //已添加过的置0
        }

        for (int i = 0; i < counts.size(); ++i)
        {
            for (int j = 0; j < counts.at(i); ++j)
            {
                res[k] = i;
                ++k;
            }
        }

        return res;
    }
};
```