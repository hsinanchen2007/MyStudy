### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char count='z';char min='z';
        for(int i=0;i<letters.length;i++){
            if(letters[i]>target)
            return letters[i];
        }  
        return letters[0];
    }
}
```