### 解题思路
C++执行用时4ms
利用数组本身记录数值是否出现过，若出现过则将对应下标数值置为0，若再次访问到数组下标为0，则说明该下标对应的数值为重复元素。
例：1，3，4，2，2
首先i=0,next记录nums[0]，令nums[0]=0，视作0已经出现过（0对检测重复数字没有影响）。数组为0，3，4，2，2
next记录nums[1],令nums[1]=0，数组为0，0，4，2，2
next记录nums[3],令nums[3]=0，数组为0，0，4，0，2
next记录nums[2],令nums[2]=0;数组为0，0，0，0，2
next记录nums[4],令nums[4]=0，数组为0,0,0,0,0
此时next=2;nums[2]=0,说明2已经出现过，因此返回2。
- 
### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int next=0;
        while(true)
        {
            next=nums[i];
            if(nums[i]==0)
            {
                return i;
            }
            nums[i]=0;//因为数组值在1到n之间，所以不会存在0，因此当i=0时，将0视作存在不会有影响。
            i=next;
        }
        return 0;
    }
};
```