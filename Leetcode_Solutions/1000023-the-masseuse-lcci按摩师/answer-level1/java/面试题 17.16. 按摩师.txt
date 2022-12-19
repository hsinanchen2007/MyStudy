### 解题思路
动态规划 双100

### 代码

```java
class Solution {
    public int massage(int[] nums) {

        int[] array = new int[nums.length];
        int max = 0;
        for (int i=0;i<array.length;i++){
            array[i] = nums[i];
            for (int j=i-2;j>=0;j--){
                array[i] = Math.max(array[j] + nums[i], array[i]);
            }
            max = Math.max(max, array[i]);
        }
        return max;
    }
}
```