将括号的深度按奇偶顺序加入A或B中，注意为了保持两个匹配括号的深度一致，左括号先加入序列在递增深度，右括号先递减深度在加入序列。
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size(),depth=0;
        vector<int> ans(n,0);
        for(int i=0;i<n;++i){
            if(seq.at(i)=='(') {
                ans[i]=depth&1;
                depth++;
            }else{
                depth--;
                ans[i]=depth&1;
            }
        }
        return ans;
    }
};
```