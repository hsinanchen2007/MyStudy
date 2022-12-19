### 解题思路
双指针

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nsize =nums.size();
        if (nsize ==0) return 0;
        int p=0,q=nsize-1;
        while (p<=q){
            if (nums[p]==val) {
                    nums[p]=nums[q];
                    q--;
            }else p++; 
        }
        return p;
    }
};
```