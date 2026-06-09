设置front、back两个索引，遍历一遍给定字符串，对每一段进行字符串翻转。
```
    string reverseWords(string s) {
        if(s.size()==0)
            return s;
        
        int front = 0;
        int back = 0;
        for(; back<s.size()-1; back++){
            if(s[back] != ' ')
                continue;
            std::reverse(s.begin()+front, s.begin()+back);
            front = back + 1;
            back = back + 1;
        }
        std::reverse(s.begin()+front, s.end());
        return s;
    }
```
