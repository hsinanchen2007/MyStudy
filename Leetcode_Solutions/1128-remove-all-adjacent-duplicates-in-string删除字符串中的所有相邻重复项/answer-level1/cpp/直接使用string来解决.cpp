没有使用迭代，主要思路就是将目前便利string中的元素与输出string 中的最后一个元素进行比较；
如果相同，则将输出string中的最后一个元素删除，不同，将原string中的当前遍历的元素放入输出string中。
![捕获.PNG](https://pic.leetcode-cn.com/616582534c97a3296dde5a2bd7f779d4f5bc7c56859efcf1ee2293ad9106f633-%E6%8D%95%E8%8E%B7.PNG)


class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        ans.push_back(S[0]);
        for(int i=1;i<S.size();i++){
            if(S[i]==ans.back()) ans.pop_back();
            else ans.push_back(S[i]);
        }
        return ans;
    }
};