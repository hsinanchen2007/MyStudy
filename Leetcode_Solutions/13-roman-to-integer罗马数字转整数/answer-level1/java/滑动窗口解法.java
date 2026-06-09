### 解题思路
1 滑动窗口

### 代码

```java
class Solution {
    public int romanToInt(String s) {
 int result = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            char c1 = (i + 1 < s.length()) ? s.charAt(i + 1) : 'O';
            if(c=='I'){
                if(c1=='V'){
                    result += 4;
                    i++;
                }else if(c1=='X'){
                    result+=9;
                    i++;
                }else{
                    result+=1;
                }
            }
            if(c=='X'){
                if(c1=='L'){
                    result += 40;
                    i++;
                }else if(c1=='C'){
                    result+=90;
                    i++;
                }else{
                    result+=10;
                }
            }

            if(c=='C'){
                if(c1=='D'){
                    result += 400;
                    i++;
                }else if(c1=='M'){
                    result+=900;
                    i++;
                }else{
                    result+=100;
                }
            }
            if(c=='V'){
                result+=5;
            }
            if(c=='L'){
                result+=50;
            }
            if(c=='D'){
                result+=500;
            }
            if(c=='M'){
                result+=1000;
            }
        }
        if(result>=4000) return 0;
        return result;
    }
}
```