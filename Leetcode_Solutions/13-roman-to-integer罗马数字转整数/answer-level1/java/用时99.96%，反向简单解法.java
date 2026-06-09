不多说，直接上代码

class Solution {
    public int romanToInt(String s) {
        int n = s.length(); 
        int ans = 0;
        int i=n-1;
        for(;i>0;i--){
            char pre = s.charAt(i-1);
            char now = s.charAt(i);
            ans += getValue(now);

            if(getValue(pre) < getValue(now)) {
                ans -= getValue(pre);
                i--;//如果前一个字符代表的值小于当前字符，跳过该字符
            }
        }

        if(i==0) ans += getValue(s.charAt(0));  //i为0时，说明第一个字符的值大于第二个字符
        return ans;
    }
    public int getValue(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
}