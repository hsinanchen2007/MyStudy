### 解题思路
将数字加入桶  桶里没有的就是缺失的数字

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int[] bucket = new int[nums.length +1];
        for(int i = 0; i < nums.length;i++){
            bucket[nums[i]] ++;
        }

        for(int i =0 ; i < bucket.length;i++){
            if(bucket[i] == 0) return i;
        }
        return -1;
    }
}
```