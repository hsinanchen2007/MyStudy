![image.png](https://pic.leetcode-cn.com/016221d2c91c21bdfbb29e1561274e177b35688d1db9c3683083752d5889bd4f-image.png)

```
class Solution {
public:
    int jump(vector<int>& nums) {
        int now=0;
        int count=0;
        while(now<nums.size()-1){
            int max=0;
            count++;
            if(nums[now]+now>=nums.size()-1)
                return count;
            for(int i=now+1;i<=nums[now]+now;i++){
                if(i+nums[i]>max+nums[max]){
                    max=i;
                }
            }
            now=max;
        }
        return count;
    }
};
```
