### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int count=0,number=0;
        for(int i=0;i<nums.length;i++){
        count+=nums[i];
        number+=i;
        }
        return number+nums.length-count;
    }
}
```