### 解题思路
官方标准解法，就是超级疑惑的是对新的字符数组初始化大小的时候，明明可以是 3 * (n - 1)
，我本地都可以通过，迷幻的测试用例。。。
![image.png](https://pic.leetcode-cn.com/edf93c682aec14ce34e51c90f5a79721cdbd2509911e7616a3ac607de58fec79-image.png)

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int strLen = s.length();
        if(0 > strLen || 10000 < strLen) {
            throw new RuntimeException("不符合条件!");
        }
        // 3(20%) * (n个字符最多有n -1个间隔，最大有 n - 1个空格)
        char[] chArr = new char[3 * (strLen)];
        int size = 0;
        for(int i = 0;  i < strLen; i++) {
            char curCh = s.charAt(i);
            if(curCh == ' ') {
                chArr[size++] = '%';
                chArr[size++] = '2';
                //chArr[size++] = '0';
            } else {
                chArr[size++] = curCh;
            }
        }
        return new String (chArr, 0, size);
    }
}
```