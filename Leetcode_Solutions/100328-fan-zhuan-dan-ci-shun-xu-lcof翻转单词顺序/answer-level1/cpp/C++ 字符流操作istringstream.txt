字符流操作 istringstream 可以分割单词并自动去除空格，然后用栈逆序。
```
class Solution {
public:
    string reverseWords(string s) {
        istringstream istr(s);
        stack<string> str_st;
        string str;
        while(istr >> str){
            str_st.push(str);
        }
        string ans;
        while(!str_st.empty()){
            ans += str_st.top();
            if(str_st.size() > 1){
                ans += " ";
            }
            str_st.pop();
        }
        return ans;
    }
};
```
