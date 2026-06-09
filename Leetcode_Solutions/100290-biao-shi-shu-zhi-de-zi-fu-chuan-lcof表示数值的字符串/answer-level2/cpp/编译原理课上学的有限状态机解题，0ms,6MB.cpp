### 解题思路
坑太多了，题目描述里给的通过样例太少了，状态机图在稿纸上改了好几次。。。
1,2,3,6,7都是终态
字符扫完能停留在状态，返回true
![img_0049.png](https://pic.leetcode-cn.com/8d8532d1e2833d162320915457a2787887ecea8ad86dbe66274339b04667cfa8-img_0049.png)


### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        char state = 's';
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            switch(state)
            {
                case 's':
                    {
                        if(ch == ' ')
                        {
                            state = 's';
                            break;
                        }
                        if(ch == '+' || ch == '-')
                        {
                            state = '0';
                            break;
                        }
                        if(ch >='0' && ch <= '9')
                        {
                            state = '1';
                            break;
                        }
                        if(ch == '.')
                        {
                            state = '8';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '0':
                    {
                        if(ch >='0' && ch <= '9')
                        {
                            state = '1';
                            break;
                        }
                        if(ch == '.')
                        {
                            state = '8';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '1':
                    {
                        if(ch == ' ')
                        {
                            state = '7';
                            break;
                        }
                        if(ch >='0' && ch <= '9')
                        {
                            state = '1';
                            break;
                        }
                        if(ch == '.')
                        {
                            state = '2';
                            break;
                        }
                        if(ch == 'e' || ch == 'E')
                        {
                            state = '4';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '2':
                    {
                        if(ch == ' ')
                        {
                            state = '7';
                            break;
                        }
                        if(ch >='0' && ch <= '9')
                        {
                            state = '3';
                            break;
                        }
                        if(ch == 'e' || ch == 'E')
                        {
                            state = '4';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '3':
                    {
                        if(ch == ' ')
                        {
                            state = '7';
                            break;
                        }
                        if(ch >='0' && ch <= '9')
                        {
                            state = '3';
                            break;
                        }
                        if(ch == 'e' || ch == 'E')
                        {
                            state = '4';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '4':
                    {
                        if(ch >='0' && ch <= '9')
                        {
                            state = '6';
                            break;
                        }
                        if(ch == '+' || ch == '-')
                        {
                            state = '5';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '5':
                    {
                        if(ch >='0' && ch <= '9')
                        {
                            state = '6';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '6':
                    {
                        if(ch == ' ')
                        {
                            state = '7';
                            break;
                        }
                        if(ch >='0' && ch <= '9')
                        {
                            state = '6';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '7':
                    {
                        if(ch == ' ')
                        {
                            state = '7';
                            break;
                        }
                        state = 'e';
                        break;
                    }
                case '8':
                    {
                        if(ch >='0' && ch <= '9')
                        {
                            state = '3';
                            break;
                        }
                        state = 'e';
                        break;
                    }
            }
            if(state == 'e')return false;
        }
        if(state == '1' || state == '2' || state == '3' || state == '6' || state == '7')return true;
        else return false;
    }
};
```