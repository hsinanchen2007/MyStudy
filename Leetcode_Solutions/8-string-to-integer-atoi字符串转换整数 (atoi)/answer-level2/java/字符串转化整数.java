```
    public int myAtoi(String str) {
        str = str.trim();
        if(str.length() == 0) return 0;
        
        int sign = 1;
        if(str.charAt(0) == '-'){
            sign = -1;
            str = str.substring(1);
        }else if(str.charAt(0) == '+'){
            sign = 1;
            str = str.substring(1);
        }
        
        long ans = 0;
        for(int i=0; i<str.length(); i++){
            char val = str.charAt(i);
            if(!Character.isDigit(val))
                break;
            
            ans = ans * 10 + (val - '0'); 
            if(ans * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            if(ans * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        }
        
        return (int)ans* sign;
    }
```
