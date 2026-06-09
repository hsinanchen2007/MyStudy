### 解题思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;划分型 $dp$ 就是要一段段划分的意思。

#### 分析
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;从最后一步出发，最后一步肯定有一个字母，这个字母变成了 $0,1，2..,25$，设字符串的长度为 $n$ ，要知道前 $n$ 个字符串翻译方式数，就要知道前 $n-1$ 和前 $n-2$ 翻译方式数，因为最后一个字母可能转换成一位数，也可能转换成两位数，即 $f[i] = f[i-1] + f[i-2]$ ， $i$ 代表字符串长度

#### 初始条件 
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;$f[0] = 1$，我就认为空串也有一种翻译方式了
#### 边界条件
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;字符串长度为 $1$，那只有一种翻译方式

#### 结果
划分型 $dp$ 一般开 $n+1$，对于空串比较好处理，结果就是 $f[n]$


### 代码

```java
class Solution {
    public int translateNum(int num) {
        char[] sc = String.valueOf(num).toCharArray();
        int n = sc.length;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            //if (sc[i - 1] >= '0' && sc[i - 1] <= '9') {
                f[i] += f[i - 1];
            //}
            if (i > 1) {
                int a = (sc[i - 2] - '0') * 10 + (sc[i - 1] - '0');
                if (a >= 10 && a <= 25) {
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
}
```