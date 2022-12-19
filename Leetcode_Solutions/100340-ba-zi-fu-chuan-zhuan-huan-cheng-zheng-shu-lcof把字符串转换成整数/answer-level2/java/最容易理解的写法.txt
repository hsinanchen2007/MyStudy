```
class Solution {

    public int strToInt(String str) {
        if(str.length() == 0){
            return 0;
        }
        char[] chars = str.toCharArray();
        int start = 0;
        for(Character c : chars){
            if(c != ' '){
                break;
            }
            start++;
        }
        if(start == str.length()){
            return 0;
        }

        int flag = 0;
        if(chars[start] == '-'){
            flag = 1;
            start++;                
        }else if(chars[start] == '+'){
            flag = 2;
            start++;
        }

        int result = 0;
        for(int i = start; i < chars.length; i++){
            if(!Character.isDigit(chars[i])){
                break;
            }
            if(((result > Integer.MAX_VALUE /10) || (result == Integer.MAX_VALUE/10 && (chars[i] - '0') >= 8 )) && flag == 1){
                result = Integer.MIN_VALUE;
                break;
            }else if(((result > Integer.MAX_VALUE /10) || (result == Integer.MAX_VALUE/10 && (chars[i] - '0') >= 7)) ){
                result = Integer.MAX_VALUE;
                break;
            }

            result = result*10 + chars[i] - '0';
        }

        if(flag == 1 && result != Integer.MIN_VALUE){
            result = result*(-1);
        }

        return result;  
    }
}
```
