### 解题思路
用了栈。感觉自己好傻。
一开始提交了几次还超时了。
一开始为了连接字符串，sprintf到数组，然后再赋值回来给string。后来改成直接用string.push_pack连接字符，用append(to_string(num)连接数字，时间就不超时，可以提交了。
看来中间折腾字符数组赋值很耗时间啊？

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
            string result="";
            stack<char> stackChar;
            char last = 0;
            int num =0;
            for ( int i =0 ;i <S.length(); i++)
            {
                char curr = S.at(i);
         
                if ( curr == last || i == 0)
                {
                    stackChar.push(curr);   
                    last = curr;
                }
                else
                {
                    num = 0;
                    while(stackChar.size()>0)
                    {
                        stackChar.pop();
                        num++;
                    }
                    result.push_back(last);
                    result.append(to_string(num));
                    last = curr;
                    stackChar.push(curr);  
                }
                 if ( i == S.length() -1 )
                        {
                                         num = 0;
                                while(stackChar.size()>0)
                                {
                                    stackChar.pop();
                                    num++;
                                }
                                result.push_back(last);
                                result.append(to_string(num));
   
                        }

            }
            if ( result.length() < S.length())
                return result;
            else
                return S;
    }
};
```