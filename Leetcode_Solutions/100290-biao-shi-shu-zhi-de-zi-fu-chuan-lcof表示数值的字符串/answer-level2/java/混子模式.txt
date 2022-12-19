### 解题思路
混子模式


### 代码

```java
class Solution {
    public boolean isNumber(String s) {
        try{
            char tmp=s.charAt(s.length()-1); 
            if(tmp!='.'&&tmp!=' '&&(tmp>'9'||tmp<'0'))return false;
            float a = Float.parseFloat(s);
            return true;
        }catch(Exception e){
            return false;
        }
    }
}
```