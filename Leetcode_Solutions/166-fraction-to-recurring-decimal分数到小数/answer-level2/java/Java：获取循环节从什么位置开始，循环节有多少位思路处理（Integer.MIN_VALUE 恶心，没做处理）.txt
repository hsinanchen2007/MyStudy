```
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0 || numerator == 0){
            return "0";
        }
        String res = "";
        if((denominator > 0 && numerator < 0) || (denominator < 0 && numerator > 0)){
            res += "-";
        }
        int s = numerator / denominator;
        int y = Math.abs(numerator % denominator);
        if(y == 0){
            return s + "";
        }
        int[] r = f(numerator, denominator); //查找 循环节长度，及第一个循环节首次出现的位置
        int length = r[0];
        int start = r[1];
        if(length == 0){
            res += str(String.valueOf(Math.abs(denominator)).length(), -1, y, Math.abs(denominator));
        }else {
            res += s + ".";
            res += str(length + start, start, y, denominator);
            res += ")";
        }
        return res;
    }
    
    public String str(int length, int start, int y, int denominator){
        String res = "";
        for(int i = 0; i < length; i++){
            y = y*10;
            if(i == start){
                res += "(" + Math.abs(y / denominator) + "";
            } else {
                res += Math.abs(y / denominator) + "";
            }
            y = Math.abs(y % denominator);
        }
        return res;
    }
    
    
    
    public int[] f(int n, int m) {
        n = n % m;
        List<Integer> v = new ArrayList<>();
        for (;;) {

            v.add(n);
            n *= 10;
            n = n % m;
            if (n == 0)
                return new int[]{0,0};
            if (v.indexOf(n) >= 0){
                int i = v.size() - v.indexOf(n);
                return new int[]{i, v.indexOf(n)};
            }
        }
    }
}
```