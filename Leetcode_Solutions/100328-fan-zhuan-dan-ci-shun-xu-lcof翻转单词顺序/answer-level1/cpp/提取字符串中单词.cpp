### 解题思路
1.可以正向遍历：ans=temp+" "+ans;
2.可以反向遍历：ans=ans+" "+temp;

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string temp="",reverse="";
        int cnt=0,space=1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') {
                space=0;//space为0表示上一个字符不是空格，为1反之
                temp+=s[i];
            }
            else{
                if(space==0){
                    temp=temp+" ";
                    reverse=temp+reverse;
                    temp="";//清空
                    space=1;
                }
            }
        }
        if(temp!="")reverse=temp+" "+reverse;//如果末尾有空格则temp="",如果没有空格则还没把最后一个单词加上，此处手动加上。
        reverse.pop_back();
        return reverse;

    }
};
```