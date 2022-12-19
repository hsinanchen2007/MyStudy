思路：
从后向前遍历数组，把能够跳跃到最后的位置用good变量保存
若当前位置能够到达good，说明其必能到达最后的位置，将good更新为当前位置
遍历直到第0个元素

```
public boolean canJump(int[] nums) {
        int good = nums.length-1;
        for(int i=nums.length-2;i>=0;i--)
            if(nums[i]+i>=good)good=i;
        return good==0;
    }
```
