### 解题思路
1. 先定义数组长度，通过循环来获取长度。
2. 然后通过Arrays.fill方法来填充数组。
3. 要注意下标，不要越界。

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int length = 0;
        for (int i = 0; i < nums.length; i++) {
            length += nums[i];
            i++;
        }
        int[] result = new int[length];

        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            Arrays.fill(result, index, index + nums[i], nums[i + 1]);
            index += nums[i];
            i++;
        }


        return result;
    }
}
```