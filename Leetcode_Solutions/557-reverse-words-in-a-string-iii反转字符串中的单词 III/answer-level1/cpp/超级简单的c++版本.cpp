使用reverse+istringstream
```
    string reverseWords(string s) {
        istringstream ss (s);
        string tmp,res;
        while(ss>>tmp){
            if(res.size()) res+=" ";
            reverse(tmp.begin(),tmp.end());
            res+=tmp;
        }
        
        return res;
    }
```
