### 解题思路

```
N : 1 => Y
N : 2 => Y
N : 3 => Y
N : 4 => N
N : 5 => Y --------先取1个，N变成4，变成Nim先手
N : 6 => Y --------先取2个，N变成4，变成Nim先手
N : 7 => Y --------先取3个，N变成4，变成Nim先手
N : 8 => N --------取1-3，都是对方赢
....
看数据就可以得出规律 n % 4 != 0时能赢。
```

![图片.png](https://pic.leetcode-cn.com/0d1c7702435ee6b55bbb82fd24e51b68a62f74bd7f3297a669e67a7e01fbae2d-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}
```