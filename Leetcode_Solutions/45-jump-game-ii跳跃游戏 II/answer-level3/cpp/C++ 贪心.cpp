### 解题思路
此处撰写解题思路
每个数字代表能跳跃的最大步数，据此可以知道其能跳跃到的区间，根据此区间选择一个进行跳跃，选择的点应满足可到达的距离最远，逐步记录即可

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int len=nums.size();
        if(len==0||len==1) return 0;
        int start=nums[0],startid=0,endid=len-1;
        if(start>=endid) return 1;
        int jumpsteps=0;
        while(1){
            int findmax=-1,maxid;
            for(int i=startid+1;i<len&&i<=start;i++){
                if(nums[i]+i>=findmax){
                    findmax=nums[i]+i;
                    maxid=i;
                }
            }
            startid=maxid;
            start=nums[startid]+startid;
            jumpsteps++;
             if(maxid+nums[startid]>=endid) return jumpsteps+1;
        }
    }
};
```