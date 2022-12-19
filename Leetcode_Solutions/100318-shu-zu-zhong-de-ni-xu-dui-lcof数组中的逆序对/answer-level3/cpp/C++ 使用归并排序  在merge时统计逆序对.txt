### 解题思路


### 代码

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;

        int count = 0;
        vector<int> temp(nums.size());
        merge_sort(count, nums, temp, 0, nums.size() - 1);

        return count;
    }

    void merge_sort(int& count, vector<int>& v, vector<int>& temp, int left, int right)
    {
        if (left == right)
            return;

        int mid = left + ((right - left) >> 1);

        merge_sort(count, v, temp, left, mid);
        merge_sort(count, v, temp, mid + 1, right);

        merge(count, v, temp, left, mid, right);
    }

    void merge(int& count, vector<int>& v, vector<int>& temp, int left, int mid, int right)
    {
        int right_begin = mid + 1;
        int temp_end = right; //注意：升序排序，初始化为right 从右向左合并
        int size = right - left + 1;

        while (mid >= left && right >= right_begin)
        {
            if (v.at(mid) <= v.at(right)) //左 <= 右
            {
                temp.at(temp_end--) = v.at(right--);
            }
            else //左 > 右 存在逆序对  逆序对个数为 right - right_begin + 1
            {
                count += right - right_begin + 1;

                temp.at(temp_end--) = v.at(mid--);
            }
        }

        while (mid >= left)
        {
            temp.at(temp_end--) = v.at(mid--);
        }

        while (right >= right_begin)
        {
            temp.at(temp_end--) = v.at(right--);
        }

        for (int i = 0; i < size; ++i)
        {
            v.at(left) = temp.at(left);
            ++left;
        }
    }
};
```