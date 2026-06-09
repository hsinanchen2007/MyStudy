### 解题思路
方法一：switch case罗列出字符和对应的数值大小。循环查找。4.9.40.90.特别对待。
方法二：判断s相邻两脚标的大小
        若左>右，则正常叠加运算。
        若右>左，则用右边对应的值 减去左边对应的值，10-1=9；

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        
        int result =0;
        for(int i =0;i<s.length();i++){
            switch(s.charAt(i))
            {
                case 'I' : result += 1;break;
                case 'V' : result +=5;break;
                case 'X' : result += 10;break;
                case 'L' : result +=50;break;
                case 'C' : result +=100;break;
                case 'D' : result +=500;break;
                case 'M' : result +=1000;break;
                default :  System.out.println("default");break;
            }
            if(i != 0)
            {
                if(((s.charAt(i) == 'V') || (s.charAt(i) == 'X')) && (s.charAt(i-1) == 'I'))
                    result = result -1*2;
                if(((s.charAt(i) == 'L') || (s.charAt(i) == 'C')) && (s.charAt(i-1) == 'X'))
                    result = result-10*2;
                if(((s.charAt(i) == 'D') || (s.charAt(i) == 'M')) && (s.charAt(i-1) == 'C'))
                    result = result-100*2;
            }
        }
        return result;
    }
}
       
```