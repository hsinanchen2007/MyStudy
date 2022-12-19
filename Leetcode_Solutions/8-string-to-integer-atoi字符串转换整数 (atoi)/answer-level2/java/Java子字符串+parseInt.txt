try catch处理溢出的情况
```Java []
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if (str.isEmpty()) return 0;
        String sub;
        char first = str.charAt(0);
        if (first == '-' || first == '+') {
            int i;
            for (i = 1; i < str.length(); ++i) 
                if (!Character.isDigit(str.charAt(i))) break;
            
            if(i == 1) return 0;
            sub = str.substring(1, i);
            return deal(sub, first == '+');
        } else if (Character.isDigit(first)) {
            int i;
            for (i = 0; i < str.length(); ++i) {
                if (!Character.isDigit(str.charAt(i))) break;
            }
            
            sub = str.substring(0, i);
            return deal(sub, true);
        } else return 0;
    }

    private int deal(String str, boolean pos) {
        int result;
        try {
            result = Integer.parseInt(str);
            if(!pos) result = -result;
        } catch (NumberFormatException e) {
            return pos ? Integer.MAX_VALUE:Integer.MIN_VALUE;
        }
        return result;
    }
}
```

