### 解题思路
1. 首先计算除去**首字母**之外的字符串中大写、小写字母的频次,分别为upperCount、lowerCount;
2. 然后分**首字母**为大小写分类讨论，首字母为大写时，其余全部为大写时，True；其余全部为小写时，True；
3. 首字母为小写时，其余全部为小写时，True。其余情况，返回False。

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int size = word.length();
        int lowerCount = 0,upperCount = 0;
        for (int i = 1; i < size ; i++) {
            if(Character.isUpperCase(word.charAt(i))){
                upperCount++;
            }else {
                lowerCount++;
            }
        }
        //首字母为大写
        if(Character.isUpperCase(word.charAt(0))){
            if(upperCount == size - 1) return true;
            if(lowerCount == size - 1) return true;
        }
        //首字母为小写
        if(Character.isLowerCase(word.charAt(0))){
            if(lowerCount == size - 1) return true;
        }

        return false;
    }
}
```