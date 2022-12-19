### 解题思路
每日打卡的难度真是每天都不一样啊，遍历一遍，我这边代码写的有点冗长，仅供参考。
这里注意可以用StringBuilder和StringBuffer来降低使用的内存空间，因为String类是不可变类，所以对String大量修改会导致常量池占用很多内存。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() <= 2)
            return S;
        StringBuilder ans = new StringBuilder();
        int count = 1;
        char c = S.charAt(0);
        for(int i = 1; i < S.length(); i++){
            if(S.charAt(i) == c)
                count++;
            else{
                ans.append(c);
                ans.append(String.valueOf(count));
                c = S.charAt(i);
                count = 1;
            }
        }
        ans.append(c);
        ans.append(String.valueOf(count));
        if(ans.length() >= S.length())
            return S;
        return ans.toString();
    }
}
```