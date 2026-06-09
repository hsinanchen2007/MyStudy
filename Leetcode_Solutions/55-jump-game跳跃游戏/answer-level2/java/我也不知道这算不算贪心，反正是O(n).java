### 解题思路
每次扫描到一个元素都更新当前最大可达值，也就是在当前i的情况下能到达的最远距离，随时更新for循环的条件，当可达i到达数组末尾时return true//说道这里我忽然想到完全不需要等到i到达数组末尾，看可达值是否大于等于数组长度就可以了。

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int len=nums.length-1;
        int temp=0;
        for(int i=0;i<=temp;i++){
            temp=Math.max(temp,nums[i]+i);
            if(i==len) return true;
        }
        return false;
    }
}
```