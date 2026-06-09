### 解题思路
不使用额外的数据结构 使用计数方式解题
思路源于 只有一种括号时,使用计数方式遇到做括号++,右括号-- ,就可以判断是否是有效括号
文章连接 https://mp.weixin.qq.com/s/oUYsCj0rS5TOct_4yLE9qA
x,y,z分别对应的是(),[],{},遇到左括号就++,右括号--;
yx,zx分别记录y,z不为0时,已出现x左括号的数量,y,z大于0时分别++,右括号--
xy,zy  同上(x,z不为0时,已出现y左括号的数量,x,z大于0时分别++,右括号--)
xz,yz  同上(x,y不为0时,已出现z左括号的数量,x,y大于0时分别++,右括号--)
以上计数数据,是解决无法判断括号先后的问题
例如:[{}],[{]} 如果不引入额外的计数变量,在--的时候就不知道{]谁是先出现的,谁是后出现的,
引入后就记录了当存在[需要--时,{或(,是否还存在,如果存在且[是最后一个`(x==1)` 那说明
之前出现了`(xz != 0 || xy != 0)`不能匹配的括号
最后判断xyz是否都为0 即可知道整个字符串是否为有效括号

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        int x = 0;
        int y = 0;
        int z = 0;
        int xy = 0;
        int xz = 0;
        int yx = 0;
        int yz = 0;
        int zx = 0;
        int zy = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                x++;
                if (y > 0) yx++;
                if (z > 0) zx++;
            } else if (s.charAt(i) == ')') {
                if (x == 1 && (xz != 0 || xy != 0)) return false;
                x--;
                if (y > 0) yx--;
                if (z > 0) zx--;
            } else if (s.charAt(i) == '[') {
                y++;
                if (x > 0) xy++;
                if (z > 0) zy++;
            } else if (s.charAt(i) == ']') {
                if (y == 1 && (yx != 0 || yz != 0)) return false;
                y--;
                if (x > 0) xy--;
                if (z > 0) zy--;
            } else if (s.charAt(i) == '{') {
                z++;
                if (x > 0) xz++;
                if (y > 0) yz++;
            } else if (s.charAt(i) == '}') {
                if (z == 1 && (zx != 0 || zy != 0)) return false;
                z--;
                if (x > 0) xz--;
                if (y > 0) yz--;
            } else {
                return false;
            }
        }
        return x == 0 && y == 0 && z == 0;
    }
}
```