### 解题思路
利用最小缺失正数处于1-size+1这个特点，而1-size这个区间的数减去1可以作为原来数组的下标。于是我们可以利用这个特点，通过改变数字对应的下标的值，来标记这个数字是否出现，当然改变value后，还要能够找回来，这里可以用上绝对值。

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int size=nums.length;
        int sum=0;
        for(int i=0;i<size;++i)
        {
            if(nums[i]==1)
                sum++;
            if(nums[i]<=0||nums[i]>size)
            nums[i]=1;
        }
        if(sum==0)
            return 1;
        
        for(int i=0;i<size;++i)
        {
            int index=Math.abs(nums[i])-1;
            nums[index]=0-Math.abs(nums[index]);
        }

        int i=0;
        for(;i<size;++i)
            if(nums[i]>0)
                break;
        return i+1;
    }
}
```