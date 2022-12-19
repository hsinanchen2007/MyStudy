### 解题思路
算法基本思想，找到等于target的值，然后把数字挪到vector的末尾，然后vector的长度减一。但这种算法有个坑，nums只有一个值时不成立，所以需要额外判断。

执行用时 :
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
10.3 MB, 在所有 C++ 提交中击败了5.22%的用户

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if(len==1&&nums[0]==val)
            return 0;
        if(len==1&&nums[0]!=val)
            return len;
        for(int i=0;i<len;i++){
            if(nums[i]==val)
            {
                move2end(nums,i);
                len--;
                i--;
            }            
        }
        return len;
    }

    void move2end(vector<int>& nums,int ind)
    {
        int temp=nums[ind];
        for(int i=ind;i<=nums.size()-2;i++)
        {
            nums[i]=nums[i+1];
        }
        nums[nums.size()-1]=temp;
    }
};
```