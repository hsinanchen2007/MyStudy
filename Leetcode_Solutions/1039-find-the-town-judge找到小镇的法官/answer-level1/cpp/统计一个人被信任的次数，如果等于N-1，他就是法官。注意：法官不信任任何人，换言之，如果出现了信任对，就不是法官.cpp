```
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> cnt(N+1);
        for(auto index : trust) 
        {
	        cnt[index[0]]--;// 法官不信任任何人：换言之，如果出现了信任对，就不是法官
	        cnt[index[1]]++;// 一个人被信任的次数
        }
        for(int i = 1; i <= N; i++ ) 
        {
            // 一个人被除自己外的所有人信任，他就是法官
        	if( cnt[i] == N-1 ) 
                return i;
        }
        return -1;
    }
};
```