自己实现' '截取
```
class Solution {
public:
    int countSegments(string s) {
        int falg = false;
        int num = 1;
        if (s.size() == 0) return 0;
        for(auto c: s)
        {
            if( c == ' ' )
            {
                falg = true;
            }
            else
            {
                if (falg == true)
                {
                    num++;
                    falg = false;
                }
            }
        }
        if (s[0] == ' ') return num-1;
        return num;
    }
};
```

利用库函数strtok
```
class Solution {
public:
    int countSegments(string s) {
        int num = 0;
        string m_s(s.c_str());
        char *pTmp = strtok(const_cast<char *>(m_s.c_str())," ");
        while(NULL != pTmp)
        {
            pTmp = strtok(NULL, " ");
            num++;
        }
        return num;
    }
};
```

