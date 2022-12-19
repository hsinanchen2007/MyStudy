```
class Solution {
    public String toHex(int num) {
        if(num == 0){
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        while(num != 0){
            int digit = 0, base = 1;;
            for(int i = 0 ; i < 4; i++){
                if((num & 1) == 1){
                    digit += base;
                }
                base <<= 1;
                num >>>= 1;
            }
            sb.append((char)(digit < 10 ? '0' + digit: 'a' + digit - 10));
        }
        return sb.reverse().toString();
    }
}
```