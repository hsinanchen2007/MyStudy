### 解题思路
初学者的笨办法：swith建立相应int型数组，然后遍历一遍特殊情况减正常加即可。16ms击败80%，8.6M击败66%

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int sum,i,n;
        n=s.length();
        int x[n];
        sum=0;
        i=0;
        while(s[i]!='\0')
        {
            switch(s[i])
            {
                case 'I':
                    x[i]=1;
                    break;
                case 'V':
                    x[i]=5;
                    break;
                case 'X':
                    x[i]=10;
                    break;
                case 'L':
                    x[i]=50;
                    break;
                case 'C':
                    x[i]=100;
                    break;
                case 'D':
                    x[i]=500;
                    break;
                case 'M':
                    x[i]=1000;
                    break;
            }
            i++;
        }
        for(int j=0;j<n-1;j++)
        {
            if(x[j]<x[j+1])
            {
                sum=sum-x[j];
            }
            else
            {
                sum=sum+x[j];
            }
        }
        return sum+x[n-1];
    }
};
```