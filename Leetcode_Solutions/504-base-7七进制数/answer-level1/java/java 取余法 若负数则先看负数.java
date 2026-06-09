这题的难点关键是边界条件能否一次考虑到

```
    public String convertToBase7(int num) {
        if(num == 0)return "0";
        boolean nagetive = num >= 0 ? false : true;  
        if(nagetive)num *= -1;
        StringBuilder ret = new StringBuilder();
        while(num > 0){
            ret.append(String.valueOf((num % 7)));
            num /= 7;
        }
        if(nagetive){
            ret.append("-");
        }
        return ret.reverse().toString();
    }
```
