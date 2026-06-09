### 解题思路

使用双指针，从头到尾和从尾到头，如果char不一样则交换。

![image.png](https://pic.leetcode-cn.com/e40bc67c1019ce7b9521a376c2acc46660fa48540c201868ee5ec413c57c7fd8-image.png)


### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int i = 0;
        int j = s.length - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                char a = s[i];
                s[i] = s[j];
                s[j] = a;
            }
            i++;
            j--;
        }
    }
}
```