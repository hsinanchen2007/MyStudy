这一题首先是判断数组和是不是4的倍数，如果不是的话，那一定不能拼成正方形。

然后，遍历一遍数组，若有一个数大于数组和/4，那么也一定不能拼成正方形。

接着就要用回溯来判断了，这题的回溯指的是，把火柴放进不同的边里去。

因此相当于，对于任意一根火柴，将火柴放入大小为4的数组某一维度中去。

直到全部的火柴处理完，在处理过程中，如果某一个边的大小已经超过数组和/4，那就

剪枝，因为这样是不可能组成正方形的。

这里的贪心在于，如果从大到小处理，那么速度将会快的很多。因此在回溯之前，先给数组排序。

java ac代码：

```
class Solution {
    public boolean makesquare(int[] nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum == 0 || sum%4 != 0)
            return false;
        int target = sum/4;
    
        for(int num : nums)
            if(num > target)
                return false;
        //从大到小的回溯，效率更高
        Arrays.sort(nums);
        backtrack(nums.length-1,nums,target,new int[4]);
        return ans;
        
    }
    boolean ans = false;
    void backtrack(int cur,int[]nums,int target,int[] temp)
    {
        if(ans)return;
        if(cur == -1)
        {
            for(int num : temp)
                if(num != target)
                    return;
            ans = true;
            return;
        }
        for(int i = 0;i < temp.length;i++)
        {
            int last = temp[i];
            temp[i] +=  nums[cur];
            if(temp[i] <= target)
                backtrack(cur-1,nums,target,temp);
            temp[i] = last;
        }
    }
}
```

