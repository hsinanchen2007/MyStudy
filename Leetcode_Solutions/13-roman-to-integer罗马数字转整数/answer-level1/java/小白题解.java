### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int romanToInt(String s) {
    int sum=0;
    for(int i=0;i<s.length()-1;i++)
      { char c=s.charAt(i);
        if(getvalue(c)>=getvalue(s.charAt(i+1)))
        {
            sum+=getvalue(c);
        }
        else{
            sum-=getvalue(c);
        }   
      }
      return sum+getvalue(s.charAt(s.length()-1));
    }
     
      private int getvalue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }

    }
}
```