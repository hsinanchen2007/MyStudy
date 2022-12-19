### 解题思路
此处撰写解题思路
击败了百分之八十五的用户
本人菜鸡一枚，看到这道题的时候想到是不是可以用异或解决，于是发现：
将数组排序后，进行一次遍历，两个两个进行异或,如果中途出现值等于0的情况，说明有相同的值，返回真，否则为假
### 代码
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++)
        {
            if((nums[i]^nums[i+1])==0)
            return true;
        }
        return false;

    }
}

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0;i<nums.length-1;i++)
        {
            if((nums[i]^nums[i+1])==0)
            return true;
        }
        return false;

    }
}
```