### 解题思路
此处撰写解题思路
只要记录当前字符上一次出现的位置即可。
### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[]m1=new int[256];
        int[]m2=new int[256];
        for(int i=0;i<s.length();i++){
            if(m1[s.charAt(i)]!=m2[t.charAt(i)])
            return false;
            m1[s.charAt(i)]=i+1;
            m2[t.charAt(i)]=i+1;
        }
        return true;
    }
}
```