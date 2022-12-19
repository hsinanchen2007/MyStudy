遇到空格就翻转之前的单词，然后拼接到结果字符串之中
```
    string reverseWords1(string s){
        int len = s.size();
        string temp = "", res = "";
        for( int i = 0; i <= len; i++ ){
            if( s[i] == ' ' || s[i] == '\0' ){
                reverse( temp.begin(), temp.end() );
                res += temp;
                res += s[i];//拼上间隔符
                temp = "";
            }else{
                temp += s[i];
            }
        }
        return res;
    }
```