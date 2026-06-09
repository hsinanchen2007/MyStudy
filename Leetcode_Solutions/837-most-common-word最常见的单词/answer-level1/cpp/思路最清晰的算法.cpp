第一次写题解
分为四个步骤
1. 将字符串大写转小写
2. 将字符串分割，调用C内置strtok函数
3. 建立map<string,int>的映射关系，并按value排序
4. 查找高频率单词是否在banned数组里面出现
```
bool cmp(pair<string,int> &a,pair<string,int> &b)
    {
        return a.second>b.second;
    }
class Solution {
public:
    typedef pair<string,int> pr;
    string mostCommonWord(string paragraph, vector<string>& banned) {
        //-----------大写转小写
        for(int i = 0;i<paragraph.length();i++)
        if(paragraph[i]<='Z'&&paragraph[i]>='A')paragraph[i]+=32;
        //---------核心代码，将字符串分割
        char d[] = "!?',;. ";
        char *s = new char[paragraph.length()+1];
        strcpy(s,paragraph.c_str());
        char *p = strtok(s,d);
        unordered_map<string,int> mp;
        vector<pr> v;
        while(p)
        {
            string t = p;
            //insert
            if(mp.count(t)<=0)
                mp[t] = 1;
            else mp[t]++;
            p = strtok(NULL,d);
        }
        //----------按map的value排序
        for(auto it = mp.begin();it!=mp.end();it++)
            {
                v.push_back(pr(it->first,it->second));
            }
        sort(v.begin(),v.end(),cmp);
        //----------查找是否在banned数组里面
        int j = 0;
        for(int i = 0;i<v.size();i++)
        {
            for(j=0;j<banned.size();j++)
            {
                if(v[i].first==banned[j])
                break;
            }
            if(j==banned.size())
                return v[i].first;
        }
        return "";
    }
};
```
