### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        if(name.equals(typed))
        return true;
        if(name.length()>typed.length())
        return false;
        int i=0,j=0;
        while(i<name.length()&&j<typed.length()){
            if(name.charAt(i)==typed.charAt(j)){
                i++;
                j++;
            }
            else if(j>0&&typed.charAt(j)==typed.charAt(j-1))
            j++;
            else return false;
        }
        if(i==name.length())
        return true;
        else return false;
    }
}
```