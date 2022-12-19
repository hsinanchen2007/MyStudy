萌新渣方法，各位大佬海涵
![image.png](https://pic.leetcode-cn.com/868536b565872b7f21128f88541d2ecd1807d95014f7d8c97bcea673e4078b7a-image.png)
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnp[3]={0};
        int idx=0;

        for(int x:nums) cnp[x]++;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<cnp[i];j++)
            {
                nums[idx++]=i;
            }
        }
    }
};
```
