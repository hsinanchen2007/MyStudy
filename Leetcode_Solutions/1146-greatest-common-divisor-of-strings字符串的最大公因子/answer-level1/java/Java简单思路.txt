### 解题思路
首先确定最大公因子的边界是最小为短字符串中的第一个字母，最大为短字符串整体，然后对短字符串取最大的因子进行判断即可，中间加上是否为因子的长度倍数即可节省算法时间。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1.length() == 0 || str2.length() == 0) return "";
        String smaller = str1.length() > str2.length() ? str2 : str1;
        String bigger = str1.length() > str2.length() ? str1 : str2;
        for (int i = 1;i <= smaller.length();++i) {//i的含义为把短的字符串几等份
            if (smaller.length() % i == 0) {
                boolean flag = true;
                // 获取待确定等分结果
                String result = smaller.substring(0, (smaller.length() / i));
                // 对smaller验证是否为因子
                for (int j = 0;j < smaller.length();j += result.length()) {
                    if (!result.equals(smaller.substring(j, j + result.length()))) {
                        flag = false;
                        break;
                    }
                }
                // 判断bigger是否能整除result
                if (bigger.length() % result.length() != 0) {
                    continue;
                }
                // 对bigger验证是否为因子
                for (int j = 0;j < bigger.length();j += result.length()) {
                    if (!result.equals(bigger.substring(j, j + result.length()))) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return result;
            }
        }
        return "";
    }
}
```