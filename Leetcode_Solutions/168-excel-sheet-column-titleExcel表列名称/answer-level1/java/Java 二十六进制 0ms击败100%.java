### 解题思路
![图片.png](https://pic.leetcode-cn.com/376cd5d1f5942cd18e578ba853528c46add72e26799c3a7636a0f31efc7d28b6-%E5%9B%BE%E7%89%87.png)

**其实我被这道题卡了蛮久的，一看就是二十六进制啊，
然后就是过不了，为什么呢？
再读题，竟然是从1开始的！！！
10进制中只有 0~9
讲道理26进制应是 0~25， 但这里是 1-26
所以要减一（参考了评论区的代码）
一开始我也想到了，所以写成 (n + 25) % 26 + 'A'
但是不行，为什么呢？评论区求教！**

### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while(n > 0){
            n --;
            char cur = (char)(n % 26 + 'A');
            n /= 26;
            sb.append(cur);
        }
        return sb.reverse().toString();
    }
}
```