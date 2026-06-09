### 解题思路
此处撰写解题思路
实际上是每必要使用双重循环的，因为要求字母的顺序不能改变，每一次字母相同后，则下一次判断应该都是在上一次判断位置之后。
### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s.charAt(i) == t.charAt(j)){
                i++;
            }
            j++;
        }
        if(i == n)
            return true;
        return false;
    }
}
```