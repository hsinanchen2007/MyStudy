```
class Solution {
public:
    /* 注意：括号对的数量和数字的数量是一致的*/
    void reverseString(string& s)
    {
        int size = s.size();
        for(int i = 0; i< size/2; i++)
        {
            char temp = s[i];
            s[i] = s[size - 1 - i];
            s[size - 1 - i] = temp;
        }
    }
    string decodeString(string s) {
        if(s.size() <= 1)
            return s;
        string res;
        stack<int> number; //处理表示数字的字符
        stack<char> letter; //存储除数字之外的字符
        
        for(int i = 0; i < s.size(); i++)
        {
            if('0' <= s[i] && s[i] <='9')
            {
                int repeat =s[i] - '0'; 
                while('0' <= s[i + 1] && s[i + 1] <= '9') //由于s最后一个字符不是数字，因此这里不用判断i + 1不会越界
                {
                    repeat = repeat*10 + s[i + 1] - '0';
                    i++;
                }
                number.push(repeat);
                continue;
            }
            
            if(number.empty())
            {
                res.push_back(s[i]); //如果此时前面的括号已经全部被处理完了，就直接追加
                continue;
            }
            
            if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || s[i] == '[')
            {
                letter.push(s[i]); 
                continue;
            }
            
            if(s[i] == ']') //如果碰到字符']'，开始处理前面的字符
            {
                string temp; //表示该[]之间的字符串
                while(!letter.empty())
                {
                    char c = letter.top();
                    letter.pop();
                    if(c == '[') //遇到第一个'['即匹配成功
                        break;
                    temp.push_back(c);      //注意此时的字符串与实际是相反的
                }
                reverseString(temp);        //反转字符串temp
                int repeat = number.top() ;  //repeat表示上述字符串重复的次数，注意此时number栈中是一定存在数字的
                number.pop();
                if(number.empty())          //如果number栈为空，说明前面的字符已处理完成，则只需追加temp的逆序即可
                {
                    for(int j = 0; j < repeat; j++) 
                        res.append(temp);
                }
                else{
                    for(int j = 0; j < repeat; j++)
                    {
                        for(int p = 0; p < temp.size(); p++)
                            letter.push(temp[p]);
                    }
                }      
            }
        }
        return res;
    }
};
```
