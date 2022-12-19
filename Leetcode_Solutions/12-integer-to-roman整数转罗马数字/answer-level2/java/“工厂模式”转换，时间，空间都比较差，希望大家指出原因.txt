```java
class Solution {
    public String intToRoman(int num) {
        int q = num / 1000;
        int b = num % 1000 /100;
        int s = num % 100 /10;
        int g = num % 10;

        StringBuilder sss = new StringBuilder();

        return sss.append(fun(q,'M',' ',' ')).
            append(fun(b,'C','D','M')).
            append(fun(s,'X','L','C')).
            append(fun(g,'I','V','X')).toString();
    }

    //工厂，用于制造出每一位的数对应的罗马数字
    private String fun(int num,char A,char B,char C) {
        String[] map = new String[10];

        switch(num){
            case 0 : return "";
            case 1 : return ""+A;
            case 2 : return ""+A+A;
            case 3 : return ""+A+A+A;
            case 4 : return ""+A+B;
            case 5 : return ""+B;
            case 6 : return ""+B+A;
            case 7 : return ""+B+A+A;
            case 8 : return ""+B+A+A+A;
            case 9 : return ""+A+C;
            default : return "";
        }
    }
}
```
