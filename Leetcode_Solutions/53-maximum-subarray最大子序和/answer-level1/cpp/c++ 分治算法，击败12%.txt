### 解题思路
递归思想，主函数中另写一个函数sub()用以递归。
分治思想即把大问题分解成小问题。本次拆分以中点为拆分点。
数组左端l，右端r，中点m。针对m点来说，最大子序列存在三种可能。1、在m左边，2、在m右边，3、包含着m。
对于1，2两种情况来说，可以用递归。
注意左边递归，需要考虑，递归至一定程度序列中只有两个元素，此时左右顶点插值为1，m=l+1，而m=(l+l+1)=l，此时不能用m-1作为右顶点。
对于第三种情况，可以用简单的贪心算法。两次遍历。从m-1遍历至l点，对每个元素累加，找最大的sum，右边同理。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int ans=0;
       ans=sub(0,nums.size()-1,nums);
       return ans;
    }

    int sub(int l,int r,vector<int>& nums){
        if(l==r) return nums[l];
        int m,left,right,mid;
        m=(l+r)/2;
        if(m-1>=l)left=sub(l,m-1,nums);
        else left=sub(l,l,nums);
        right=sub(m+1,r,nums);
        mid=cro(m,l,r,nums);
        left=max(left,right);
        return max(left,mid);
    }

    int cro(int m,int l,int r,vector<int>& nums){
        int sum=0,maxl=0,maxr=0;
        for(int i=m-1;i>=l;i--){
            sum+=nums[i];
            maxl=max(maxl,sum);
        }
        sum=0;
        for(int i=m+1;i<=r;i++){
            sum+=nums[i];
            maxr=max(maxr,sum);
        }
        return maxl+nums[m]+maxr;
    }

};
```