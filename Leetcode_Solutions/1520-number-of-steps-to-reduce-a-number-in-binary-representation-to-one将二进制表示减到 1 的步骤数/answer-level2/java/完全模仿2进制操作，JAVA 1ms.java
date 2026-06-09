### 解题思路
用一个left和一个right分别记录我们所操作的二进制数的位置（当然这里的left总是0可以去掉）。
除以2相当于右移一位，也就是right左移。
加1的话需要模仿二进制加法，遇到111...111的特殊情况可能会导致left左移而越界，好在这种情况下已经可以知道还需要多少次操作便可以得到需要的1（因为+1后就是1000...000的格式，只需要不断除以2，需要的次数就是0的个数）。

![1.png](https://pic.leetcode-cn.com/b6fb42afde9d102fc01c8e442d8fdf712bef1a56006c3152e5b416e28d0d3cc0-1.png)


### 代码

```java
class Solution {
    public int numSteps(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = s.length() - 1;
        int count = 0;
        while (left < right) {
            if (chars[right] == '0') {
                ++count;
                --right;
            }
            else {
                count += 2;
                boolean carry = true;
                --right;
                for (int i = right; i >= left; --i) {
                    if (carry) {
                        if (chars[i] == '1') {
                            chars[i] = '0';
                            if (i == left) {
                                return count + right - left + 1;
                            }
                        }
                        else {
                            chars[i] = '1';
                            carry = false;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return count;
    }
}
```