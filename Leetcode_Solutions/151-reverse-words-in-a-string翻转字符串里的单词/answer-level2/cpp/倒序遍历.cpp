应该是第三次看到这个题了，思路简单。
去除单词前后的空格，从后向前遍历，遇到空格就把遍历到的单词加到结果中。
```
string reverseWords(string s) {
        string res="";
        if(s==" " || s=="") return res;
        int len=0;
        int start=0,end=s.length()-1;
        //if(end==start) return "";
        while( start<s.length()&& s[start]==' ') start++;
        while( end>=0&&s[end]==' ' ) end--;
        for(int i=end;i>=start;i--){
            len++;
            if(s[i]==' '){
                res+=s.substr(i+1,len-1);
                while(s[i]==' ') i--;
                i++;
                len=0;
                res+=' ';
            }
            //len++;
            if(i==start){
                res+=s.substr(i,len);
            }
        }
        return res;
    }
```
