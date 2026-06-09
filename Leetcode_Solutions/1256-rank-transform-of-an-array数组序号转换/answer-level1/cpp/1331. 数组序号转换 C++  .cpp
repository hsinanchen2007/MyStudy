### 解题思路
1、排序、去重、二分查找

### 代码

```cpp
class Solution {
public:

    //二分查找
    int binary_search(vector<int>& arr, int num)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);

            if (arr.at(mid) == num)
            {
                return mid;
            }
            else if (num < arr.at(mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {

        if (arr.empty())
        {
            return arr;
        }

        //拷贝、排序
        vector<int> arr_copy(arr.begin(), arr.end());
        sort(arr_copy.begin(), arr_copy.end());

        //去重
        vector<int> v;
        v.reserve(arr_copy.size());
        v.push_back(arr_copy.at(0));
        for (int i = 1; i < arr_copy.size(); ++i)
        {
            if (arr_copy.at(i) != v.back())
            {
                v.push_back(arr_copy.at(i));
            }
        }

        //遍历原数组，在排序去重后的数组中二分查找
        vector<int> res;
        res.reserve(arr.size());
        res.push_back(binary_search(v, arr.at(0)) + 1);

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr.at(i + 1) == arr.at(i)) //相同的数只查找一次
            {
                res.push_back(res.back());
            }
            else
            {
                res.push_back(binary_search(v, arr.at(i + 1)) + 1);
            }
        }

        return res;
    }
};
```