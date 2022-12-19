### 解题思路
此处撰写解题思路

使用数组的数据结构实现

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if( astr == null || astr.isEmpty() ){
            return true;
        }
        String [] strArr =  new String[astr.length()];
        for ( int i=0;i< astr.length() ;i++ ){
            String str = astr.charAt( i )+"";
            int index = str.hashCode() % astr.length();
            String temp = strArr[index];
            if( temp==null ){
                strArr[index] = str;
            }else{
                if( temp.indexOf( str ) >=0 ){
                    return false;
                }else{
                    strArr[index] = temp.concat( str );
                }
            }
        }
        return true;
    }
}
```