### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int num = 1;
    public int myAtoi(String str) {
        str = str.trim();
        char[] ch = str.toCharArray();
        str = "0";
        for(int i = 0;i<ch.length;i++){
            if(i == 0 && ch[i] == '-'){
                num *= (-1);
            }else if(i == 0 && ch[i] == '+'){
                num *= 1;
            }else{
                if(isTrue(ch[i])){
                    str += ch[i];
                }else{
                    break;
                }
            }
        }
        try{
            return Integer.parseInt(str)*num;
        }catch(Exception e){
            if(num > 0){
                return 2147483647;
            }else{
                return -2147483648;
            }
        }
    }

    private boolean isTrue(char letter){
        switch(letter){
            case '1': return true;
            case '2': return true;
            case '3': return true;
            case '4': return true;
            case '5': return true;
            case '6': return true;
            case '7': return true;
            case '8': return true;
            case '9': return true;
            case '0': return true;
        }
        return false;
    }
}
```