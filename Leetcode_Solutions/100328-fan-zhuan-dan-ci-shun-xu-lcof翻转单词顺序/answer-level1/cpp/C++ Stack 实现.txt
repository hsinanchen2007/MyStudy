### 解题思路
遍历一遍，记录下每个单词的首字母和尾字母，存到栈中，再依次弹出。
思路还挺简单的，直接看代码吧。
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int length=s.size();
        string ans;
        stack<int> record;
        int counter=0;
        for(int i=0;i<length;i++)
        {
            if(s[i]!=' '&&(i==0||s[i-1]==' '))
            record.push(i);
            if(s[i]!=' '&&(i==length-1||s[i+1]==' '))
            record.push(i);
        }
        while(record.size()>=1)
        {
            int a=record.top();
            record.pop();
            int b=record.top();
            record.pop();
            ans.append(s,b,a-b+1);
            if(record.size()>0)ans.append(" ");
        }
        return ans;

    }
};
```