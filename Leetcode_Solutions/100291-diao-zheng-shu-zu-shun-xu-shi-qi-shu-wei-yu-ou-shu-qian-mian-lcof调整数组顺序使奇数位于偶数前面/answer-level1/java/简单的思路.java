### 解题思路
老往复杂了去想 做出来的更差劲。。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int[] arr  = new int[nums.length];

        int left = 0;
        int right = nums.length -1;
        for (int i = 0; i < nums.length ; i++) {
           int value = nums[i];

           if (value%2 == 0 ) {
               arr[right] = value;
               right--;
           } else {
               arr[left] = value;
               left++;
           }
        }
        return arr;
    }
}
```