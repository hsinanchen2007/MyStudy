### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countLetters(String S) {
        int res=0;
        char [] ch=S.toCharArray();
        int i=0,j=0;
        while(i<ch.length){
            while(j<ch.length&&ch[j]==ch[i])
                j++;
            res+=(j-i+1)*(j-i)/2;
            i=j;
        }
        return res;
    }
}
```