### 解题思路
归并排序 在merge中统计  
对原数组 构造其每个元素索引的数组， 对该索引数组进行归并排序 降序 (比较大小是基于原数组的值，但排序的是其值对应的索引)  
因为如果对原数组排序后，原数组的值就乱了, 无法找到原数组值的位置 去统计个数

### 代码

```cpp
class Solution {
public:
    // 1、暴力法 超出时间限制
    // vector<int> countSmaller(vector<int>& nums) {

    //     vector<int> count(nums.size());

    //     for(int i = 0; i < nums.size(); ++i)
    //     {
    //         for(int j = i + 1; j < nums.size(); ++j)
    //         {
    //             if(nums.at(j) < nums.at(i))
    //             {
    //                 ++count.at(i);
    //             }
    //         }
    //     }

    //     return count;
    // }

    //2、归并排序
    void merge(vector<int>& nums, vector<int>& indices, vector<int>& tmp, int left, int mid, int right, vector<int>& res)
    {
        int left_begin = left;
        int right_begin = mid + 1;

        int i = left; //临时数组起始下标

        while (left_begin <= mid && right_begin <= right)
        {
            if (nums.at(indices.at(left_begin)) > nums.at(indices.at(right_begin)))
            {
                res.at(indices.at(left_begin)) += right - right_begin + 1;

                tmp.at(i++) = indices.at(left_begin++);
            }
            else
            {
                tmp.at(i++) = indices.at(right_begin++);
            }
        }

        while (left_begin <= mid)
        {
            tmp.at(i++) = indices.at(left_begin++);
        }

        while (right_begin <= right)
        {
            tmp.at(i++) = indices.at(right_begin++);
        }

        //拷贝回索引数组
        for (int i = left; i <= right; ++i)
        {
            indices.at(i) = tmp.at(i);
        }
    }

    void merge_sort(vector<int>& nums, vector<int>& indices, vector<int>& tmp, int left, int right, vector<int>& res)
    {
        if (left == right)
        {
            return;
        }

        int mid = left + (right - left) / 2;

        merge_sort(nums, indices, tmp, left, mid, res);
        merge_sort(nums, indices, tmp, mid + 1, right, res);

        merge(nums, indices, tmp, left, mid, right, res);
    }

    vector<int> countSmaller(vector<int>& nums) {

        vector<int> res(nums.size());

        if (nums.size() <= 1)
        {
            return res;
        }

        vector<int> indices(nums.size()); //索引数组
        for (int i = 0; i < nums.size(); ++i)
        {
            indices.at(i) = i;
        }

        vector<int> tmp(nums.size());

        merge_sort(nums, indices, tmp, 0, nums.size() - 1, res);

        return res;
    }
};
```