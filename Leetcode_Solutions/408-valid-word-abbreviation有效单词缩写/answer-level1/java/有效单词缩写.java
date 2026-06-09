### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        //模拟法
        int abbIndex=0,  add;
        for(int i=0;i<word.length();i++)
        {
            if(abbIndex>=abbr.length())
                return false;
            if(abbr.charAt(abbIndex)>='0'&&abbr.charAt(abbIndex)<='9'){
                if(abbr.charAt(abbIndex)=='0')
                    return false;
                add=0;
                while(abbIndex<abbr.length()&&abbr.charAt(abbIndex)>='0'&&abbr.charAt(abbIndex)<='9')
                {
                    add=add*10;
                    add+=Integer.valueOf(abbr.charAt(abbIndex)-'0');
                    abbIndex+=1;
                }
                i+=add-1;
                if(i+1>word.length())
                    return false;
                continue;
            }
            else if(abbr.charAt(abbIndex)!=word.charAt(i))
                return false;

            abbIndex++;
        }
        if(abbIndex<abbr.length())
            return false;
        return true;
    }
}
```