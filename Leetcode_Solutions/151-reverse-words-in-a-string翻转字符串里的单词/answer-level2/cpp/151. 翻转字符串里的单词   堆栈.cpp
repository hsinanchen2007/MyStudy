### 解题思路
注意1.开头空格不要，所以while去头
2.由于不是遇到一个空格就切分，而 是多个
所以，虽然遇到空格就要操作，但要加个条件————针对多个连续空格条件
 也就是if(!temp.empty())当前temp是否为空

3.当对象是堆栈时候，要先计算长度，再for：for(int i=0;i<strsize-1;i++){

### 代码

```cpp

class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        string res;
        
        int f=0;
        s+=' ';
        while (s[0] == ' ')  //删除字符串前的空格，可以用来检测整个字符串是否都是空格
        {
            s.erase(0,1);
        }
        if(s.empty()) return s;
        string temp;
        for(int i=0;i<s.length();i++){
         if(s[i] == ' ' || s[i] == '\0') //当遇到空格或'\0'，若temp里面有单词，压入栈mid
            {
                if(!temp.empty())
                {
                    sta.push(temp);
                    temp = "";
                }
            }
            else //若遇到字母，先加到temp内，使他成为一个完整的单词
            {
                temp = temp + s[i];
            }
            }   
  int strsize = sta.size();
         for(int i=0;i<strsize-1;i++){
            string t=sta.top();
            sta.pop();
            res=res+t+' ';
        }

        res = res + sta.top(); //手动添加最后一个单词，因为之前添加单词时，会在末位添加空格。最后一个不需要空格
        
        return res;
    }
};
```