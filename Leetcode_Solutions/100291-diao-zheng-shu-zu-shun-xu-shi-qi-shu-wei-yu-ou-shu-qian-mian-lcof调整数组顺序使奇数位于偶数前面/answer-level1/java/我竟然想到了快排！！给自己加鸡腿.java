### 解题思路
执行用时 : 2 ms , 在所有 Java 提交中击败了 99.97% 的用户 
内存消耗 : 47.8 MB , 在所有 Java 提交中击败了 100.00% 的用户

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int partIndex = 0;
        for(int i=0;i<nums.length;i++){
            int current = nums[i];
            if((current&1)==1){
                //奇数
                nums[i] = nums[partIndex];
                nums[partIndex] = current;
                partIndex++;
            }
        }
        return nums;
    }
}
```