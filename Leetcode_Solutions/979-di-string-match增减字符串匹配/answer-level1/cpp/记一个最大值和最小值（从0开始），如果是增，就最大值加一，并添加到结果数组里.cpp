记一个最大值和最小值（从0开始），如果是增，就最大值加一，并添加到结果数组里；如果是减，就最小值减一，并添加到结果数组里。最后都让它们变成非负数，即加上最小值（负数）的绝对值
```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        if(S.size() < 0) return ans;
        int sMax(0), sMin(0);
        ans.push_back(0);
        for(auto &ch : S)
            if(ch == 'I')     ans.push_back(++sMax);
            else              ans.push_back(--sMin);
        for(int i=0; i< ans.size(); i++)
            ans[i] += abs(sMin);
        return ans;
    }
};
```
