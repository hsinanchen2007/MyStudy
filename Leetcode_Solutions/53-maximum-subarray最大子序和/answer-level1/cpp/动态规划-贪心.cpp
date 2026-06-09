### 解题思路
动态规划
初次接触时我的考虑方向一直都是从当前点向后看，遇到一个负值就保存当前最大和，然后如果加上这个负值之后仍大于0就可以继续延伸，反之从下一个点从0开始重录，这样最后也做出来了，但思路不流畅，代码不优雅。其实从动态规划的角度应该是从当前点向前看，利用前面的积累。
1）首先每个子数组都是以一个数组元素结尾，最大和子数组也不例外，所以我们可以求出以每个元素结尾的子数组的最大和，最后选取其中最大的。
2）初始状态是temp_max=nums[0],然后求修改求以nums[1]结尾的最大和子数组，显然如果nums[0]<=0,那么就是他本身，反之则是nums[1]=nums[1]+nums[0],temp_max=max(nums[0],nums[1]).再然后则是求以nums[2]结尾的最大和子数组，我们知道以nums[2]结尾那么必然要想前延伸，而此时我们不要自己去延伸，因为nums[1]就是从nums[1]向前延伸的最大和，我们只需要考虑nums[1]，其大于0，则nums[2]=nums[1]+nums[2],反之不必修改nums[2].之后的都则么判断nums[i-1]表示从nums[i-1]向前延伸的最大结果，那么nums[i]只需要考录nums[i-1],因为nums[i]和nums[i-1]前向延伸的路径是一样的。

### 代码

```cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp=nums[0];//初始状态
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)
                nums[i]=nums[i]+nums[i-1];
            temp=max(nums[i],temp);
        }
        return temp;
    }
};
```