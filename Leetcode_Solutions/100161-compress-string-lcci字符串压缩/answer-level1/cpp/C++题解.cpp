![image.png](https://pic.leetcode-cn.com/9c4a988f48af9385b908c97c765ab423edd8a3217c4861c709385014c6ceb103-image.png)
```
class Solution {
public:
    string compressString(string S) {
        string retval;
        int num = 1;
        int temp = S[0];
        for(int i = 1; i < S.size(); i++)
        {
            if(S[i] != S[i - 1])
            {
                retval += temp;
                retval += to_string(num);
                num = 0;
            }
            temp = S[i];
            num ++;
        }
        retval += temp;
        retval += to_string(num);
        return retval.size() < S.size() ? retval : S;
    }
};
```