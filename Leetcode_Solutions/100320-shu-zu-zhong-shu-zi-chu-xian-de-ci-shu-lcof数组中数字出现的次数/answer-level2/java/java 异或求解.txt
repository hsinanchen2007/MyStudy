### 解题思路
1. 假设 x, y为最终结果
2. 求出 z = x ^ y;
3. 保留 z 中第i位 1 其他置为 0，得出 z1
4. 说明第i位，x 与 y 是两个不同的值，根据这个值，将x,y 分到两组
5. 每一组用异或求出唯一个不同的数据即可

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        int[] result = new int[2];
        int xorResult = 0;
        for (int i = 0; i < nums.length; i++) {
            xorResult ^= nums[i];
        }

        int diff = 1;
        while (xorResult > 0) {
            if ((xorResult & 1) == 1) {
                break;
            }
            xorResult >>= 1;
            diff <<= 1;
        }
        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] & diff) == 0) {
                result[0] ^= nums[i];
            } else {
                result[1] ^= nums[i];
            }
        }
        
        return result;
    }
}
```