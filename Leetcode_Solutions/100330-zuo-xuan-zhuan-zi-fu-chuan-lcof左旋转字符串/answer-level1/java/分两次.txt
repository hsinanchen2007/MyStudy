### 解题思路
此处撰写解题思路

### 代码
时间复杂度：两次循环的时间O(s.length())
空间复杂度：O(3)
```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuffer A=new StringBuffer();
        char a;
        for(int i=n;i<s.length();i++){
            a=s.charAt(i);
            A.append(a);
        }
        for(int i=0;i<n;i++){
            a=s.charAt(i);
            A.append(a);
        }
        return A.toString();
    }
}
```