### 解题思路
调用switch结构对不同情况下的解决方案进行分类。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(auto b = s.begin(); b != s.end(); ++b)
        {
           switch(*b)
           {
               case 'I':
                    if(b + 1 != s.end() && *(b + 1) == 'V' )
                    {    sum += 4;  ++b;}
                    else if(b + 1 != s.end() && *(b + 1) == 'X')
                    {    sum += 9;  ++b;}
                    else
                        sum += 1;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if(b + 1 != s.end() && *(b + 1) == 'L' )
                    {    sum += 40;  ++b;}
                    else if(b + 1 != s.end() && *(b + 1) == 'C')
                    {    sum += 90;  ++b;}
                    else
                        sum += 10;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if(b + 1 != s.end() && *(b + 1) == 'D' )
                    {    sum += 400;  ++b;}
                    else if(b + 1 != s.end() && *(b + 1) == 'M')
                    {    sum += 900;  ++b;}
                    else
                        sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
           }
        } 
        return sum;
    }
};
```