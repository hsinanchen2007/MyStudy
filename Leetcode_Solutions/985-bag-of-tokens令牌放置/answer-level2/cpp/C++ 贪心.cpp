#### 解题思路
- 排序
- 尽可能多的将符合条件的令牌放正得分
- 能量不够时考虑放弃一个分，得到尽可能多的能量
- 需要考虑到异常终止情况，即当前得分已经为负值
```cpp
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty()) return 0;
        sort(tokens.begin(),tokens.end());//排序
        int res=INT_MIN,energy=P,socre=0; 
        int len = tokens.size();
        int i=0,j=len-1;
        while(i<=j){//贪心求解策略
            while(i<=j && energy>=tokens[i]){//尽可能多的将符合条件的令牌放正得分
                energy -= tokens[i];
                ++socre;
                ++i;
                res = max(res,socre);
            }
            if(i<=j && energy<tokens[j]){//能量不够时考虑放弃一个分，得到尽可能多的能量
                energy += tokens[j];
                --socre;
                --j;
            }
            if(socre<0) break;//此时说明已经不可能在进行下一步操作了，直接退出
        }
        return max(res,0);
    }
};
```
