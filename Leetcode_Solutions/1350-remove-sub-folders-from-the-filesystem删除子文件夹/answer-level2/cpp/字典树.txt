```
class Solution {
public:
    struct node {//定义结点
        bool flag;//标志目录结尾
        unordered_map<string,int> next;//子目录
    };
    int index = 1;
    node rec[400000];
    vector<string> ans;
    vector<string> removeSubfolders(vector<string>& folder) {
          sort(folder.begin(),folder.end(),cmp);//从长度小的开始插入
          for(auto& s: folder) if(insertion(get(s))) ans.push_back(s);
          return ans;
    }
    static bool cmp(const string& a, const string& b) {
        return a.length() < b.length();
    }
    vector<string> get(string s) {//格式化目录字符串
        vector<string> res;
        string tmp;
        s.push_back('/');
        for(int i=1;i<s.length();i++) {
            if(s[i]!='/') tmp.push_back(s[i]);
            else {
                res.push_back(tmp);
                tmp = "";
            }
        }
        return res;
    }
    bool insertion(vector<string> s) {//尝试插入，如果不成功则返回false
        static int i,cur;
        for(int i=cur=0;i<s.size();i++) {
            if(!rec[cur].next.count(s[i])) rec[cur].next[s[i]] = index++;
            cur = rec[cur].next[s[i]];
            if(rec[cur].flag) return false;
        }
        return rec[cur].flag = true;//标记结尾
    }
    
};
```
