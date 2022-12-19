讲真题我是真没看懂，官方题解真好。
就奇数偶数分类就行，实际上很简单
```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans;
    int depth=0;

    for(int i =0;i<seq.size();i++){
        if(seq[i]=='('){
            ans.push_back(depth%2);
            depth++;
        }
        else{
            depth--;
            ans.push_back(depth%2);
        }
    }
    return ans;
    }
};
```

