### 解题思路
看来解析，把之前那个最大的问题解决了。就是当数组里面有“大数”的时候。这个算法直接将超过nums长度的数字置一。
1、首先对nums处理。超过nums数组数组大小的数字或者小于1的数字全部置1.因为超过数组大小的数字已经没有作用了。根本就轮不到对他进行比较。
2、和之前写的一样，把nums数字对应的下标置一。
3、注意后面返回语句return i、return size + 1.
如果在数组中找到就返回数组中对应的位置。否则就是前面数字前面有（1-n）。所以返回size + 1.


### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool exist1 = false;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            if (nums[i] == 1) {
                exist1 = true;
                break;
            }
        if (!exist1)
            return 1;
        int* temp = new int[size + 1];            
        for (int i = 0; i < size; i++) {
            temp[i] = 0;            
            if (nums[i] <= 0 || nums[i] > size)
                nums[i] = 1;
        }
        temp[size] = 0;
        for (int i = 0; i < size; i++)
            temp[nums[i]] = 1;
        for (int i = 1; i < size + 1; i++)
            if (temp[i] == 0)
                return i;
        return size + 1;
    }
};
```