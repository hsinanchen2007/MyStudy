先上代码
```
class Solution {
public:
    
    string slower(const string &str){
        string temp=str;
        for(auto &s: temp){
            s=tolower(s);
        }
        return temp;
    }
    string replace(const string &str){
        string temp=str;
        for(auto &j: temp){
            if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u')
                j='.';
        }
        return temp;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        map<string,pair<vector<string>,vector<string>> >hash;
        for(auto &i : wordlist){
            string temp = replace(slower(i)); 
            hash[temp].first.push_back(i);
            hash[temp].second.push_back(slower(i));
        }
        // for(auto i:hash){
        //     cout<<"first:"<<i.first<<"second:";
        //     cout<<"pair.1:";
        //     for(auto j:i.second.first){
        //         cout<<j<<" ";
        //     }
        //     cout<<"pair.2:";
        //     for(auto j:i.second.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto &i: queries){
            auto it = hash.find(replace(slower(i)));
            if(it==hash.end()){
                res.push_back("");
            }else{
                 auto match = find(it->second.first.begin(),it->second.first.end(),i);
                 if(match!=it->second.first.end()){
                     res.push_back(i);
                 }else{
                     auto matchlow = find(it->second.second.begin(),it->second.second.end(),slower(i));
                     if(matchlow!=it->second.second.end()){
                         int index = matchlow-it->second.second.begin();
                         string s=*(it->second.first.begin()+index);
                         res.push_back(s);
                     }else{
                         res.push_back(it->second.first.front());
                     }
                 }
       
            }
        }
        return res;
    }
};
```

刚开始看到这个map<string, pair< vector<string>,vector<string> > >数据结构我是惊呆的。后面在阅读代码的时候发现这种数据结构虽然复杂，但是对题目的解答有很大的帮助。
后面代码思路很清晰。共有四种可能：
1. 第一种什么都不匹配，放入空字符串。
2. 第二种全文完全匹配，放入原文。
3. 第三种匹配小写字符串，并根据小写字符串的位置放入原字符串。
4. 最后一种既不匹配全文，又不匹配小写字符串，但是元音匹配，则放入wordlist里面第一个与它元音匹配的项目。

最后附上原博客地址：https://blog.csdn.net/tomwillow/article/details/85389299 
