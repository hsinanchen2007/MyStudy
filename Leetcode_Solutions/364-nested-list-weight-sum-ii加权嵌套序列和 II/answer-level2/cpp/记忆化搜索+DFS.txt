
建立memo数组，采用记忆化搜索方式保存每一层节点的之和，之后再计算深度


```c++
class Solution {
    private:
long long sum = 0;
int maxDepth = 0;
int memo[0xfff];
void calculate(NestedInteger &nl,int depth){
    if(nl.isInteger()){
        memo[depth] += nl.getInteger();
        maxDepth = max(maxDepth,depth);
    }else{
        for(auto &i:nl.getList()){
            calculate(i,depth+1);
        }
    }
}
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        fill(memo,memo+0xfff,0);
        for(auto &i: nestedList){
            calculate(i,0);
        }
        for(int j=1,i=maxDepth;i>=0;i--,j++){
            // cout << j << "*" << memo[i] << "\t";
            sum+=j*memo[i];
        }
        return sum;
    }
};
```
