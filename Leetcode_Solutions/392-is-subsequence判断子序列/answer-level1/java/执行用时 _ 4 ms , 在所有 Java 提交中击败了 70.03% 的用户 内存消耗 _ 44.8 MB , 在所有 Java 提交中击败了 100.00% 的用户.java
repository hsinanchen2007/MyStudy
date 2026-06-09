### 解题思路
第n次成功判断一个字符都生成一个新的子字符串，第n+1次判断则是基于这个新的字符串
dp(n+1) 基于dp(n) 
因为题目要求的就是顺序不能乱，所以第二个字符在第一个字符前的情况并不符合条件
首先读取子字符串的一个字符，然后进行匹配，假如匹配到就把字符串就把前面的字符串删掉

例如 子集{abc} 原字符串{qqqqqcccccbbbbb a qqqqeee c b ggg c}
匹配到a之后直接删掉前面的字符串，得到{qqqqeee c b ggg c}
第二次需要匹配b，也是把前面的字符串删掉得到{ggg c}
最后再匹配c就可以了

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index;
        for(int i = 0; i < s.length(); i++){
            index = t.indexOf(s.charAt(i));
            if(index == -1){
                return false;
            }
            t = t.substring(index+1);
        }
        return true;
    }
}
```