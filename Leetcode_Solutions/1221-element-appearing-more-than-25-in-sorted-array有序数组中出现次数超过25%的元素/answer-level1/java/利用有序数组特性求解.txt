### 解题思路
1. 求出 25% 对应的出现次数threshold
2. 遍历数组
3. 由于是有序数组，只需比较 当前位置 i 值和 i + threshold的值是否相等即可
![image.png](https://pic.leetcode-cn.com/04500e357eb58050f541298a63926f969cec36f65d73c4d4fe0c4d85912cc660-image.png)

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        int threshold = arr.length / 4;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i + threshold] == arr[i]) {
                return arr[i];
            }
        }
        return 0;
    }
}
```