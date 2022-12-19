### 解题思路
先处理特殊规则，然后直接map取值

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        Map<String, Integer> digitMap = new HashMap<String, Integer>();
        digitMap.put("I" ,1);
        digitMap.put("V" , 5);
        digitMap.put("X" , 10);
        digitMap.put("L" , 50);
        digitMap.put("C" , 100);
        digitMap.put("D" ,500);
        digitMap.put("M" , 1000);

        int curPos = 0;
        int ans = 0;
        char nextChar = '0';
        while(curPos < s.length()) {
           char ch = s.charAt(curPos);
           if(curPos + 1 < s.length()) {
                switch(ch) {
                    case 'I' : 
                        nextChar = s.charAt(curPos + 1);
                        if(nextChar == 'V') {
                            curPos += 2;
                            ans += 4;
                            continue;
                        } else if(nextChar == 'X') {
                            curPos += 2;
                            ans += 9;
                            continue;
                        }
                    break;
                    case 'X' :
                        nextChar = s.charAt(curPos + 1);
                        if(nextChar == 'L') {
                            curPos += 2;
                            ans += 40;
                            continue;
                        } else if(nextChar == 'C') {
                            curPos += 2;
                            ans += 90;
                            continue;
                        }
                    break;
                    case 'C' :
                        nextChar = s.charAt(curPos + 1);
                        if(nextChar == 'D') {
                            curPos += 2;
                            ans += 400;
                            continue;
                        } else if(nextChar == 'M') {
                            curPos += 2;
                            ans += 900;
                            continue;
                        }
                    break;
                }
           }
           
           ans += digitMap.get(String.valueOf(ch));
           curPos ++;
        }
        return ans;
        
    }
}
```