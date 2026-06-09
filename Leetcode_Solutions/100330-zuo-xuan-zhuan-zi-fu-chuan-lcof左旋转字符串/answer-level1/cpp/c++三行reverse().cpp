举个例子：输入 abcdefg n=2
逆转前两个元素 **ba**cdefg  &ensp;&ensp;reverse(s.begin(), s.begin()+n); 
逆转后五个元素 ab**gfedc**  &ensp;&ensp;reverse(s.begin()+n, s.end());
逆转全部元素   &ensp;&ensp;**gfedcba**&ensp;&ensp;reverse(s.begin(), s.end());
over
```
string reverseLeftWords(string s, int n) {  
        reverse(s.begin(), s.begin()+n);    
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
```
