### 解题思路
1、观察一下，除第一个字母以外其他字母大小写必须一致，判断一波
2、如果除第一个字母外都是大写，则第一个字母也必须是大写，再判断一波
3、其他情况都满足

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.length()<=1)
        {
            return true;
        }
        //除了第一个字母，其他必须大小写一致
        boolean isUpper=false;
        int i=1;
        do{
            char c=word.charAt(i);
            if(i!=1&&isUpper!=(c-'a')<0)
            {
                return false;
            }
            isUpper=(c-'a')<0;
            i++;
        }
        while(i<word.length());
        //如果全是大写，则第一个字母也必须是大写
        if(isUpper&&(word.charAt(0)-'a')>0)
        {
            return false;
        }
        return true;
    }
}
```