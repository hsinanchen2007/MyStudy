第一种是用了map和set
用i和k分别指向pattern和str中的元素。用map将str中的单词和pattern中的字母一一对应起来，用set存放单词，避免重复。可能表述得不明白，自己看吧。
![image.png](https://pic.leetcode-cn.com/eb3cd5bea7aa9a902b586e8016aa49a3dde10f91223f03b0ffcdf1bfb3bf5908-image.png)


```
bool wordPattern(string pattern, string str) {
        string res="";string s;map<string,char> m;set<char> se;
        int i,k;
        for(i=0,k=0;i<str.length()&&k<pattern.length();i++){
            if(str.at(i)!=' '&&i<str.length()-1) s+=str.at(i);
            //当截出来一个单词之后
            else
            {
                if(i==str.length()-1)
                    s+=str.at(i);
                if(m.find(s)==m.end()) {
                    if(se.count(pattern.at(k))) return false;
                    m.insert(pair<string, char>(s,pattern.at(k)));
                    se.insert(pattern.at(k));
                }
                res+=m[s];
                k++;
                s="";
            }
            
        }
        if(i<str.length()-1||k<pattern.length()-1) return false;
        return res==pattern;
    }
```

第二种就用了两个map来做，通过map将两个字符串转换成相同的字符串，这里比较麻烦
![image.png](https://pic.leetcode-cn.com/591fea08e2dcd1fc16c0657fb1ae8e18f6f568362ff1b20b0a1e99cfc10c9cf3-image.png)

```
bool wordPattern(string pattern, string str) {
        int j1=0;string res1="";string s1;map<char,char> m1;
        for(int i=0;i<pattern.length();i++){
            if(m1.find(pattern.at(i))==m1.end()) m1.insert(pair<char, char>(pattern.at(i),'a'+j1++));
            res1+=m1[pattern.at(i)];
        }


        int j=0;string res="";string s;map<string,char> m;
        for(int i=0;i<str.length();i++){

            if(str.at(i)!=' '&&i<str.length()-1) s+=str.at(i);
            else
            {
                if(i==str.length()-1)
                    s+=str.at(i);
                if(m.find(s)==m.end()) m.insert(pair<string, char>(s,'a'+j++));
                res+=m[s];
                s="";
            }
            
        }
        return res==res1;
    }
```
