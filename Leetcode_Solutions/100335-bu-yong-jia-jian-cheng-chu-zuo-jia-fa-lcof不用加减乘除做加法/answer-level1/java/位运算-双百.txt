### 解题思路
int遍历32位，选择性置位
置位 
    对比进位和两个数当前位上是0是1，
        当3个1 则进位c和当前位均置为1；
        2个1则进位c=1，当前位位0；
        1个1则进位为0，当前位为1；
        0个1则进位和当前位均为0；
进位
左移
**无符号右移**

### 代码

```java
class Solution {
    public int add(int a, int b) {
        int res = 0,c=0; //进位
        for (int i=0; i<32; i++) {
            int mask = 1<<i;
            int am = (a&mask)>>>i; //无符号右移
            int bm = (b&mask)>>>i;
            if (c>0&&am>0&&bm>0) {
                c = 1;
                res |= mask;
            } else if (c>0&&am>0||c>0&&bm>0||am>0&&bm>0) { //两个
                c=1;
            } else if(c>0||am>0||bm>0) { // 1个
                res |= mask;
                c=0;
            } else { //0
                c=0;
            }
        }
        return res;
    }

}
```
![image.png](https://pic.leetcode-cn.com/828beefa2cc21069a69bf344a39c9ade9af50118bedba8300dca985ad689dd8a-image.png)
