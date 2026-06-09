### 解题思路
minsum：到i-1为止最小前缀和
pre：求0-i位的和
不断用pre-minsum更新答案。
O（n）
![image.png](https://pic.leetcode-cn.com/64555890d6a298fd3e32d03a775ce4b6e91d5fe332a72f04f6926e752519a9cd-image.png)


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int minsum=0;
        int pre=0;
        int ans=-100000;

        for(int i=0;i<n;i++){
            pre+=nums[i];
            ans=Math.max(ans,pre-minsum);
            minsum=Math.min(pre,minsum);
        }
        return ans;
    }
}
```