### 解题思路
首先看题我们可以知道，我们的问题是将数组nums里的值与val进行匹配；如果值相同则过滤，值不相同就需要将该值重新赋给nums数组。好接下来说说我的结题思路：
相同留下，不同则不处理它。

```
这里判断这样用，是为了更好的节省资源if(nums[i]!=val)
```

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for(int i = 0; i<nums.length;i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
}
```