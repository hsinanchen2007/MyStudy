算法思想是：
首先对数组进行排序。

设置变量i，代表 有可能 组成 三角形的 第三条边 的下标，i从nums.lengh-1 到 2。

对于每个i，设置滑动窗口l=0,r=i-1。

若nums[l]+nums[r] > nums[i]那么有

nums[l+1]+nums[r] > nums[i]

nums[l+2]+nums[r] > nums[i]

....

nums[r-1]+nums[r] > nums[i]


此时把结果ans 加上 r-l，表示有r-l个可行解。并且把r-1，使得滑动窗口向左缩小（含义是减小第二条边，看看是否还能组成三角形）。

否则l+1，使得滑动窗口向右缩小（含义是增大第一条边，看看是否能组成三角形）。

java 代码：

```
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        
        int ans = 0;
        
        for(int i = nums.length-1;i >= 2;i--)
        {
            int l = 0,r = i-1;
            while(l < r)
                if(nums[l] + nums[r] > nums[i])
                {
                    ans += r-l;
                    r--;
                }
            else
                l++;
            
        }
        return ans;
        
    }
   
    
}
```


