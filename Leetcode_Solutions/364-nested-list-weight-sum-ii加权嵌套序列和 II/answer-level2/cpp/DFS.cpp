1.求出序列的最大深度。
2.DFS时，当前层的深度直接求出来即可。


```
class Solution {
public:
    int depth(vector<NestedInteger>& nestedList){
        int ans = 1;
        for(auto v: nestedList){
            if(!v.isInteger()){ ans = max(depth(v.getList())+1,ans);}
        }
        return ans;
    }
    int helper(vector<NestedInteger>& nestedList,int curr_depth,int depth){
        int ans = 0;
        for(auto v: nestedList){
            if(v.isInteger()){ ans += v.getInteger()*(depth-curr_depth);}
            else{ ans += helper(v.getList(),curr_depth+1,depth);}
        }
        return ans;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int d = depth(nestedList);
        return helper(nestedList,0,d);
    }
};
```