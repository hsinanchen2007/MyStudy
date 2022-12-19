1. 特殊字符4，5，9处理后为：IV,V,IX。对应关系分别为：主字符放右边副字符放左边，主字符，下一位的主字符放右边福字符放左边。
2. 遍历数字，当前位数字符为tmp=(int)(num/Math.pow(10,i)),同时num%=(int)(num/Math.pow(10,i)),其中i=n:0,n为数字位数减1.
3. class Solution {
    public String intToRoman(int num) {
        int n = 0;
        int num1 = num;
        while(num1>0) {
            n++;
            num1/=10;
        }
        StringBuilder charISB = new StringBuilder();
        charISB.append('I');
        charISB.append('X');
        charISB.append('C');
        charISB.append('M');
        String charI = charISB.toString();
        StringBuilder charVSB = new StringBuilder();
        charVSB.append('V');
        charVSB.append('L');
        charVSB.append('D');
        String charV = charVSB.toString();
        int tmp;
        
        StringBuilder resSB = new StringBuilder();
        for (int i = n-1; i >= 0; --i) {
            tmp = (int)(num/Math.pow(10,i));
            num %= (int)(Math.pow(10,i));
            if (tmp==4) {
                Character c1 = charV.charAt(i);
                Character c2 = charI.charAt(i);
                resSB.append(c2);
                resSB.append(c1);
            } else if (tmp == 5) {
                Character c1 = charV.charAt(i);
                resSB.append(c1);
            } else if (tmp==9) {
                Character c1 = charI.charAt(i+1);
                Character c2 = charI.charAt(i);
                resSB.append(c2);
                resSB.append(c1);
            } else if (tmp>5) {
                Character c1 = charV.charAt(i);
                Character c2 = charI.charAt(i);
                resSB.append(c1);
                for (int j = 0; j < tmp-5; ++j) {
                    resSB.append(c2);
                }
            } else if (tmp<5) {
                // Character c1 = charV.charAt(i);
                Character c2 = charI.charAt(i);
                for (int j = 0; j < tmp; ++j){
                    resSB.append(c2);
                }
                // resSB.append(c1);
                    
            }
                
        }
        return resSB.toString();
    }
}