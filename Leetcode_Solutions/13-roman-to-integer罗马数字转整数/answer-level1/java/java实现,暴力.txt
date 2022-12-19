```
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1) {
                if (s.charAt(i) == 'I' && s.charAt(i + 1)=='V') {
                    sum = sum + 4;
                    i++;
                }else if (s.charAt(i) == 'I' && s.charAt(i + 1)=='X') {
                    sum = sum + 9;
                    i++;
                }else if (s.charAt(i) == 'X' && s.charAt(i + 1)=='L') {
                    sum = sum + 40;
                    i++;
                }else if (s.charAt(i) == 'X' && s.charAt(i + 1)=='C') {
                    sum = sum + 90;
                    i++;
                }else if (s.charAt(i) == 'C' && s.charAt(i + 1)=='D') {
                    sum = sum + 400;
                    i++;
                }else if (s.charAt(i) == 'C' && s.charAt(i + 1) == 'M') {
                    sum = sum + 900;
                    i++;
                } else {
                    sum = sum + returnNum(s.charAt(i));
                } 
                
                
            } else {
                sum = sum + returnNum(s.charAt(i));
            }
        }
        return sum;
    }
    
    public static int returnNum(Character character) {
        int num = 0;
        switch (character) {
            case 'I':
                num = 1;
                break;
            case 'V':
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L':
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
        }
        return num;
    }
    
}
```
