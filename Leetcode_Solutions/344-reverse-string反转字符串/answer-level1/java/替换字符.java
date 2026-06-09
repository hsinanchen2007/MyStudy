### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int i=0,j=s.length-1;
        char t;
        while(i<j){
            t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
    }
}
```