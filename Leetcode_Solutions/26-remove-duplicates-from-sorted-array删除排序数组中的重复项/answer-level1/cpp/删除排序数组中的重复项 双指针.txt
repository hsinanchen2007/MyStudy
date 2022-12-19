### 解题思路
双指针，第一个指针p1跑在前面，侦测有没有与前一个重复，第二个指针跑在后面，更改新的数组值。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return n;
        int p1=1,p2=0;
        while(p1<n){
            if(nums[p1]!=nums[p2])nums[++p2]=nums[p1];
            p1++;
        }
        return ++p2;
    }
};
```