### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int count=0;
for(int i=0;i<nums.length+1;i++)
count+=i;
for(int i=0;i<nums.length;i++)
count-=nums[i];
return count;
    }
}
```