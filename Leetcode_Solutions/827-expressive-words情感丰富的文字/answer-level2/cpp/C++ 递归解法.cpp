c++ 递归解法
```cpp
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for(auto&str:words){
            if(str.size()<=S.size() && extend(str, 0, S,0))
            {
                ans++;
                printf("%s\n", str.data());
            }
        }
        return ans;
    }

    bool extend(const string& source, int idx1, const string& target, int idx2){
        if(idx1>=source.size() && idx2 >= target.size())
            return true;
        else if(idx1>=source.size())
            return false;
        else if(source[idx1]!= target[idx2])
            return false;
        
        int sourceCnt = 1;
        while(idx1+1<source.size() && source[idx1] == source[idx1+1]){
            idx1++;
            sourceCnt++;
        }
        int targetCnt = 1;
        while(idx2+1<target.size() && target[idx2] == target[idx2+1]){
            idx2++;
            targetCnt++;
        }
        if(sourceCnt != targetCnt && targetCnt <3)
            return false;
        return extend(source, idx1+1, target, idx2+1);
    }
};
```