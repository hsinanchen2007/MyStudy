**分析：**
1.法官需要被N-1个人相信
2.法官不相信任何人（关键）且只有一个法官
3.trust[i] 是完全不同，trust[i][0] != trust[i][1]，说明一个人最多被相信N-1次
**思路：**
1.统计每个人被相信的次数
2.如果某人相信别人，则将其被相信的次数减1
2.如果某个人被相信的次数为N-1则其为法官（如果其相信别人，则被相信次数达不到N-1）
**代码**
 int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1) return N;
        vector<int> trusted;
        trusted.resize(N+1,0);
        for(vector<int> &tru:trust)
        {
            ++trusted[tru[1]];      //有人相信tru[1]，则相信人数+1
            --trusted[tru[0]];      //tru[0]相信别人，则相信其的人数-1，保证相信其的人数不为N-1
        }
        
        for(int i=1;i<=N;++i)
        {
            if(trusted[i]==N-1)
                return i;
        }
        return -1;
        
    }