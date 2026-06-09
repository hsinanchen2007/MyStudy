### 解题思路
判断短字符串中的每一个字符是否在长字符串中出现，并且后一个字符一定要在排除前一个字符的剩余长字符串中寻找
### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = -1;
        for(char ch : s.toCharArray())
        {
            i = t.indexOf(ch,++i);
            if(i == -1)
            {
                return false;
            }
        }
        return true;
    }
}
```