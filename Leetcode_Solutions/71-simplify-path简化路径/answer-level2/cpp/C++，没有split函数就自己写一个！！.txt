**自己实现一个按照指定字符对字符串进行分割的函数，全当练习字符串了。**
```
class Solution {
    void split(string& s, vector<string>& v, string c)
    {
        int start, end;
        start = 0;
        end = s.find(c);
        while(end != std::string::npos)
        {
            string tmp = s.substr(start, end-start);
            if(tmp != "")
                v.push_back(s.substr(start, end-start));
        
            start = end + c.size();
            end = s.find(c, start);
        }
        if(start != s.length())
            v.push_back(s.substr(start));
    }
public:
    string simplifyPath(string path) {
        vector<string> path_list;
        vector<string> path_list2;
        string res = "/";
        split(path, path_list, "/");
        for(string p : path_list){
            if(p == ".") continue;
            else if(p == "..") {
                if(!path_list2.empty())
                    path_list2.pop_back();
                continue;
            }
            path_list2.push_back(p);
        }
        for(int i = 0; i < path_list2.size(); i++){
            if(i != 0) res += "/" + path_list2[i];
            else res += path_list2[i];
        }
        return res;
    }
};
```

