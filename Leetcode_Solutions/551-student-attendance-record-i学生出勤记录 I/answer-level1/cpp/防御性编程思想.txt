先在首尾添加到场'P',字符串长度增加2
然后从1开始遍历字符串，统计A 的个数以及是否有连续3个及以上的L
最后判断即可~~
```
public:
    bool checkRecord(string s) {
        s.insert(s.begin(),'P');
        s.push_back('P');
        int n = s.size();
        int A_num = 0;
        int P_tag = 0;
        for(int i = 1; i < n - 1; ++i)
        {
            if(s[i] == 'A')
                A_num++;
            if(s[i] == 'L' && s[i - 1] == 'L' && s[i + 1] == 'L')
                P_tag = 1;
        }
        return (A_num <= 1 && P_tag == 0) ? true : false;
    }
};
```
如果有帮助就点个赞吧~~