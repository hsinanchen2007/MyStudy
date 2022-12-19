### 解题思路
（1）除去首末的空格
```
        while(s[0]==' '){
            s.erase(s.begin());
        }
        while(s[s.size()-1]==' '){
            s.erase(prev(s.end()));
        }
```
（2）依次记录单词的字母，直到遇到空格，则将单词入栈
```
        stack<string> sta;
        string temp = "";
        for(char i:s){
            if(i==' '&&temp==""){
                continue;
            }else if(i==' '&&temp!=""){
                sta.push(temp);
                temp.clear();
            }
            else{
                temp += i;
            }
        }
        sta.push(temp);  //最后一个单词后没有空格，需要单独压入栈
```
（3）逐个将栈中的单词pop
```
        string result = "";
        while(!sta.empty()){
            result += sta.top() + ' ';
            sta.pop();         
        }
        result.erase(prev(result.end())); //最后单词后多余一个空格，需要去除
```


### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        while(s[0]==' '){
            s.erase(s.begin());
        }
        while(s[s.size()-1]==' '){
            s.erase(prev(s.end()));
        }
        stack<string> sta;
        string temp = "";
        for(char i:s){
            if(i==' '&&temp==""){
                continue;
            }else if(i==' '&&temp!=""){
                sta.push(temp);
                temp.clear();
            }
            else{
                temp += i;
            }
        }
        sta.push(temp);
        string result = "";
        while(!sta.empty()){
            result += sta.top() + ' ';
            sta.pop();         
        }
        result.erase(prev(result.end()));
        return result;
    }
};
```