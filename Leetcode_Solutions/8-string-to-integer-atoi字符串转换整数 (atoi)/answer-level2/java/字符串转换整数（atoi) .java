```
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if(str.equals("")) return 0;
        boolean isPositive = true;
        boolean fin = false;
        int start = 0;
        StringBuilder sb = new StringBuilder("");
        char[] chs = {'0','1','2','3','4','5','6','7','8','9','+','-'};
        char first = str.charAt(0);
        for(int i = 0 ; i < chs.length ; i++){
            if(first==chs[i])break;
            if(i== chs.length-1) return 0;
        }
        switch(first){
            case '-':isPositive =false;
            case '+':start=1;
                    if(str.length()==1) return 0;
        }
        for(int i = start ; i < str.length() && !fin ; i++){
            fin = true;
            for(int j = 0 ; j < 10 ;  j ++){
                if(str.charAt(i)==chs[j]) {
                    fin =false;
                    sb.append(chs[j]);
                    break;
                }
                else if(i==1&&start==1&&j==9) return 0;
            }
        }
        double doub = Double.valueOf(sb.toString());
        if(doub>2147483647&&isPositive) return 2147483647;
        else if(doub > 2147483647) return -2147483648;
        if(isPositive) return (int)doub;
        else return (int)-doub;
    }
}
```
