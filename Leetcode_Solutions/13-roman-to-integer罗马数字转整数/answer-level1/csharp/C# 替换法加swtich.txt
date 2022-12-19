方法的思路主要利用C#的字符串替换方法，将两个特殊字符换成1个。用时128ms，战胜98.52%
```sh
public class Solution {
    public int RomanToInt(string s) {
        s=s.Replace("IV","Y");
        s=s.Replace("IX","T");
        s=s.Replace("XL","U");
        s=s.Replace("XC","R");
        s=s.Replace("CD","O");
        s=s.Replace("CM","W");
        int sum=0;
        int i=0;
        for (i=0;i<s.Length;i++){
            switch (s[i]){
                case 'M':
                    sum+=1000;
                    break;
                case 'W':
                    sum+=900;
                    break;
                case 'D':
                    sum+=500;
                    break;
                case 'O':
                    sum+=400;
                    break;    
                case 'C':
                    sum+=100;
                    break;
                case 'R':
                    sum+=90;
                    break;
                case 'L':
                    sum+=50;
                    break;
                case 'U':
                    sum+=40;
                    break;
                case 'X':
                    sum+=10;
                    break;
                case 'T':
                    sum+=9;
                    break;
                case 'V':
                    sum+=5;
                    break;
                case 'Y':
                    sum+=4;
                    break;
                case 'I':
                    sum+=1;
                    break;
            }
        }
        return sum;
    }
}
```
