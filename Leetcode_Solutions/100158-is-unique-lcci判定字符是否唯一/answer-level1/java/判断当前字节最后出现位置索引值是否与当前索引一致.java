### 解题思路
先排空,然后遍历字符串,判断当前字节最后出现位置是否与当前位置一致

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if("".equals(astr)) {return true;}
        
        char c;
        for(int i = 0; i < astr.length(); i++){
            c = astr.charAt(i);
            if(astr.lastIndexOf(c) != i){
                return false;
            }
        }
        return true;
    }
}
```