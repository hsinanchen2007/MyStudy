### 解题思路
第一个和最后一个互换
第二个和倒数第二个互换
第三个和倒数第三个互换
....
依此类推

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        for(int i=0;i<(s.length)/2;i++){
            char temp = s[i];
            s[i]=s[s.length-1-i];
            s[s.length-1-i]=temp;
        }
    }
}
```