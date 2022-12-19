- 利用一个变量num记录'L'('R')的数量，遍历字符串s，如果字符为'L'('R')，则num++，否则num--

- 当num为0时，之前出现的'L'和'R'的数量必定相等，此时将记录子串数量的res++，遍历完后返回res即可

```
class Solution {
    public int balancedStringSplit(String s) {
        int num = 0;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == 'L')
                num++;
            else
                num--;
            if(num == 0)
                res++;
        }
        return res;
    }
}
```
