![image.png](https://pic.leetcode-cn.com/ab22c36d42178b645d754941f57beb961ac8352311ff69e5233915c77c866290-image.png)
解题思路：统计输入的vector中每个字符串每种字母出现的最小次数。
```
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int count[26];
        for(int i=0;i<26;i++)
            count[i]=101;
        for(int i=0;i<A.size();i++)
        {
            int tmp[26]={0};
            for(int j=0;j<A[i].size();j++)
                tmp[A[i][j]-'a']++;    
            for(int i=0;i<26;i++)
                count[i]=min(count[i],tmp[i]); 
        }

        for(int i=0;i<26;i++)
            if(count[i])
                for(int j=0;j<count[i];j++){
                string str;
                str.push_back('a'+i);
                res.push_back(str);
                }
        return res;
    }
```

