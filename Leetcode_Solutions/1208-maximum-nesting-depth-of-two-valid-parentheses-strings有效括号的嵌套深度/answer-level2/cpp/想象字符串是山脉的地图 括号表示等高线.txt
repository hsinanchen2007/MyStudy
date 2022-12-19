不知道会不会形象点
现在就是拦腰切一刀 把山顶移下来 让山脚和山顶的部分高度一样

假设原字符串的最大深度为m 那么划分A B的公共最小深度为m-m/2
所以只要把原来深度大于m/2的括号从A挪到B就可以了
最后返回A B分组情况
```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        stack<int> s;
        int m=0;
        for(int i{0};i<seq.size();i++){
            if(seq[i]=='('){
                ans.push_back(s.size());
                s.push(s.size());
                m=max(m,s.top()+1);
            }
            else{
                s.pop();
                ans.push_back(s.size());
            }
        }
        m/=2;
        for(int i{0};i<ans.size();i++){
            ans[i]>=m?ans[i]=1:ans[i]=0;
        }
        return ans;
    }
};
```
