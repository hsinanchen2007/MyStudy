### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if(str == null || str.length() == 0){
            return 0;
        }
        str = str.trim();
        boolean zf = str.charAt(0) == '-' ? true : false;
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < str.length(); i++){
            if(i == 0 && (zf || str.charAt(i) == '+')){
                continue;
            }
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9'){
                sb.append(str.charAt(i));
            }else{
                break;
            }
        }
        if(sb.length() == 0){
            return 0;
        }
        StringBuffer temp = new StringBuffer();
        for(int i = 0; i < sb.length(); i++){
            if(sb.charAt(i) == '0'){
                continue;
            }else{
                temp.append(sb.substring(i));
                break;
            }
        }
        if(temp.length() == 0){
            return 0;
        }
        String ss = temp.toString();
        if(zf && (ss.length() > 11 || -Long.parseLong(ss) <= Integer.MIN_VALUE)){
            return Integer.MIN_VALUE;
        }else if(!zf && (ss.length() > 11 || Long.parseLong(ss) > Integer.MAX_VALUE)){
            return Integer.MAX_VALUE;
        }else{
            if(zf){
                int num = Integer.parseInt(ss);
                return -num;
            }else{
                return Integer.parseInt(ss);
            }
        }
    }
}
```