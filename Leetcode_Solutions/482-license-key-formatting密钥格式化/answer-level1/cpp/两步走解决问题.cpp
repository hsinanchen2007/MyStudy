```
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int cnt = 0;
        int len = S.size();
        string temp = "";
        for(int i = len - 1; i >= 0; i--){ // 第一步：将小写字母转化为大写字母，并且去掉'-'
            if(S[i] >= 'a' && S[i] <= 'z'){
                S[i] -= 32;
            }
            if(S[i] == '-'){
                continue;
            }
            temp += S[i];
        }
        string res = "";
        len = temp.size();
        for(int i = 0; i < len; i++){// 第二步：插入 '-'
            if(cnt == K){
                cnt = 0;
                res += '-';
            }
            cnt++;
            res += temp[i];
        }
        reverse(res.begin(),res.end()); // 反转一下就OK啦
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/210ade44d9b014f3bef4b8f7bc08bf1c025e60c2f195c52ca9eac2f60bcd18b6-1.png)
