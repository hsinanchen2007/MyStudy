```
直接上代码
vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int>res;
        if(s.size()==0||words.size()==0)return res;
        int len=words[0].size();
        int num=words.size();
        string sub1,sub2;
        //key是单词，value是该单词出现的次数
        unordered_map<string,int> m;
        unordered_map<string,int> tem;
        for(string t:words)m[t]++;
        for(int i=0;i<s.size()-len*num+1;i++)
        {
            //sub1是子串，长度是len*num
            sub1=s.substr(i,len*num);
            for(int j=0;j<sub1.size()-len+1;j=j+len)
            {
                //sub2是sub里的单个单词
                sub2=sub1.substr(j,len);
                if(m.count(sub2)==0)break;
                else tem[sub2]++;
            }
            if(tem==m)res.push_back(i);
            tem.clear();
        }
        return res;
    }
```
参考了别人的题解，由于我太菜了，我也不知道这是什么解法（狗头）
因为我看C++的代码比较少，我就发出来供参考啦~~