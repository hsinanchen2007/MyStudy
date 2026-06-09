初始化计数器为0，遍历字符串，遍历到每个字符时，让计数器加1，如果当前字符与下一个字符不等，就把当前字符和计数器值追加到结果字符串，并把计数器置零。
```c
class Solution {
public:
    string compressString(string S) {
        int cnt=0;
        string r;
        for(int i=0; i<S.size(); i++){
            cnt++;
            if(S[i]!=S[i+1]){
                r.push_back(S[i]);
                r+=to_string(cnt);
                cnt=0;
            }
        }
        if(r.size()<S.size())
            return r;
        return S;
    }
};
```
