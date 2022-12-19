### 解题思路
递归实现

### 代码

```java
class Solution {
      public boolean isUnique(String astr) {
        char[] chars = astr.toCharArray();
        return isUnique(0,chars);
    }

    public boolean isUnique(int l,char [] chars){
        if(l == chars.length){
            return true;
        }
        for(int i = l+1; i < chars.length; i++){
            if(chars[l] == chars[i]){
                return false;
            }
        }
        return isUnique(l+1,chars);
    }
}
```