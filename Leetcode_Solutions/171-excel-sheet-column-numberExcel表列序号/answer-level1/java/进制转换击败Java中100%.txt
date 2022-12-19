### 解题思路

跟之前的Excel序号问题一样，也是进制转换的问题：

1. 通过从后往前循环并使用`s.charAt(i) - 'A'`获得当前位的乘数
2. 使用`k *= 26`在循环中不断增长当前位的底数
3. 计算`int b = n >= 26 ? 0 : 1`解决进位过程的问题
4. 最后将每位字母的结果累加即可

![image.png](https://pic.leetcode-cn.com/9a0dfa7f8027a96bda426cd603e565322e257a2a2b569c2b5d6501aa5571dc64-image.png)

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        int res = 0;
        int k = 1;
        int i = s.length() - 1;
        while (i >= 0) {
            int n = s.charAt(i) - 'A';
            int b = n >= 26 ? 0 : 1;
            res += (n + b) * k;
            k *= 26;
            i -= 1;
        }
        return res;
    }
}
```