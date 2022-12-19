### 解题思路
1.可以用 DFA全称为：Deterministic Finite Automaton,即确定有穷自动机
2.先合法的字符串位置。然后算值。
3.对于过大的数，用长度来判定是否超过max
4.对于 00000000000000030 这种较长的数，需要特殊处理，去掉前面的多个0

### 代码

```cpp
class Solution {
public:

    bool isF(char c)
    {
        return c=='-'||c=='+';
    }

    bool isS(char c)
    {
        return c<='9'&&c>='0';
    }

    int getsize(string str) {
    
        int size = 0;
        for(auto &it:str)
        {
            if(isF(it))
            {
                continue;
            }

            if(it=='0')
            {
                size++;
            }
            else
            {
                break;
            }
        }
        return size;
    
    }
    int myAtoi(string str) {
        
        int start = 0;
        int end = 0;
        for(auto& it :str)
        {
            if(it == ' ')
            {
                start++;
                continue;
            }
            if(isF(it)||isS(it))
            {
                break;
            }
            else
            {
                return 0;
            }
            start++;
        }

        for(auto& it :str)
        {
            if(end>start)
            {
                if(!isS(it))
                {
                    break;
                }
            }
            end++;
        }

        end;
        int size = end - start;
      //  cout<<start<<" "<<end<<endl;
        string s(str.begin()+start,str.begin()+end);
        int x = getsize(s);      
        if(size == 0)
        {
            return 0;
        }
        if(size - x>13)
        {
            if(s[0] == '-')
            {
                return  INT_MIN;   
            }
            else
            {
                return INT_MAX;
            }
        }

        if(size==1&&isF(s[0]) == true)
        {
            return 0;
        }

        int flag = 1;
        long num = 0;
        for(auto& it:s)
        {
            if(it == '-')
            {
                flag = -1;
            }
            else if(it == '+')
            {

            }
            else
            {
                num = num*10 + it - '0';
            }
        }

        num *= flag;

        if(num >INT_MAX)
        {
            return INT_MAX;
        }
        else if(num <INT_MIN)
        {
            return INT_MIN;
        }

        return num;


    }
};
```