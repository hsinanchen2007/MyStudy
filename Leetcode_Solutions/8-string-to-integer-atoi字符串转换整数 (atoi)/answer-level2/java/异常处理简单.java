### 解题思路
1. 判断加异常处理

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if(str.length() == 0 || Character.isLetter(str.charAt(0)) ) return 0;
        char[] a = str.toCharArray();
        boolean fu = false;
        int i = 0;
        if(str.startsWith("-")){
            fu = true;
            i = 1;
        }
        if(str.startsWith("+")){
            fu = false;
            i = 1;
        }
        String num = "";
        for ( ; i< a.length; i++){
            if(Character.isDigit(a[i])){
                if(num.length() == 0 && (""+a[i]).equals("0")){
                    continue;
                }
                num  +=""+a[i]+"";
            }else {
                break;
            }
        }
        if(num.length() == 0){
            return 0;
        }
        

        try{
            return !fu ? Integer.valueOf(num) : Integer.valueOf("-"+num);
        }catch (Exception e){
            if(fu) return Integer.MIN_VALUE;
            else return Integer.MAX_VALUE;
        }
    }
}
```