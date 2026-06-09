### 解题思路
![QQ截图20200331204715.png](https://pic.leetcode-cn.com/cd213487b83d6ea65d7e4a94c5e79541239026c3a856387aece30bbaaada5849-QQ%E6%88%AA%E5%9B%BE20200331204715.png)
思路很简单：遍历字符串，如果是I，X，C之类的字符，检查后一位是否是V,X. L,C D,M ，如果是就改变符号。没有特殊情况的直接加上continue就完事

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int sum = 0 ;
        for (int i = 0; i <s.length() ; i++) {
            switch (s.charAt(i)){
                case 'V' : sum+=5; continue;
                case 'L' : sum+=50; continue;
                case 'D' : sum+=500; continue;
                case 'M' : sum+=1000; continue;
                case 'I' :
                    if (i==s.length()-1){
                        sum += 1 ;
                        break;
                    }
                    sum += (s.charAt(i+1)=='V'||s.charAt(i+1)=='X') ? -1 :1 ;
                    continue;
                case 'X' :
                    if (i==s.length()-1){
                        sum += 10 ;
                        break;
                    }
                    sum += (s.charAt(i+1)=='L'||s.charAt(i+1)=='C') ? -10 :10 ;
                    continue;
                case 'C' :
                    if (i==s.length()-1){
                        sum += 100 ;
                        break;
                    }
                    sum += (s.charAt(i+1)=='D'||s.charAt(i+1)=='M') ? -100 :100 ;
                    continue;
            }
        }
        return  sum;
    }
}
```