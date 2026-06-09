### 解题思路
if-else走天下

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int n = str.length();
        if(n == 0) return 0;
        boolean isVaild = false;
        int start = 0;
        int result = 0;
        boolean isNeg = false;
        StringBuilder sb = new StringBuilder();
        //判断字符串是否能进行转换，若能，记录起点位置
        for(int i = 0; i < n; i++){
            char c = str.charAt(i);
            if(c != ' '){
                start = i;
                if(c == '-' || Character.isDigit(c) || c == '+'){
                    isVaild = true;
                }
                break;
            }
        } 
  
        //将数字依次放入StringBuilder中，遇到第一个不是数字的就停下
        if(isVaild){
            if(str.charAt(start) == '-'){
                isNeg = true;
                start++;
            }else if(str.charAt(start) == '+'){
                start++;
            }
            for(int i = start; i < n; i++){
                char c = str.charAt(i);
                if(Character.isDigit(c)){
                    sb.append(c);
                }else{
                    break;
                }
            }
        }

        //将字符串转换为int，抛出异常捕获之
        try{
            if(sb.length() != 0){
                int number = Integer.parseInt(sb.toString());
                result = isNeg ? -number : number;
            }
        }catch(Exception e){
            result =  isNeg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }

        return result;
    }
}
```