### 解题思路
1. 从第一开始累加，一正一负相加为零
2. 判断n是奇数还是偶数，奇数 第一个为0，否则第一个为1
![image.png](https://pic.leetcode-cn.com/1f7281abe840e742ba4ec077f76a81e7167a4a0edba2770eb7ade3e967f700ff-image.png)

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        int num = (n & 1) == 0 ? 1 : 0;
        for (int i = 0; i < n; i++) {
            result[i] = num;
            num = 0 - num;
            if (num >= 0) {
                num++;
            }
        }
        return result;
    }
}
```