**抖个机灵，大佬们勿喷呀。当然效率相对于自己构造的常数会大点，因为源码好像有做了一个减法求区间长度好像。不过还行，能接受**

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target) return it - nums.begin(); return -1;
    }
};
```