# **思路**
1、遍历一遍colsum，记one为colsum中为1的个数，two为colsum中为2的个数；
2、upper-two即为第一行中需要增加的1，lower-two为 第二行中需要增加的1；
3、如果two>upper || two>lower || one+two*2!=upper+lower返回空；
4、使用一个unordered_set记录colsum为1的位置，在第一行中填前upper-two个，剩下的填到第二行；

# **代码**
```
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int len=colsum.size();
        vector<vector<int>> res(2,vector<int>(len,0));
        unordered_set<int> st;
        int one=0,two=0;
        for(int i=0;i<len;++i){
            if(colsum[i]==2){
                ++two;
                res[0][i]=1;
                res[1][i]=1;
            }
            else if(colsum[i]==1){
                ++one;
                st.insert(i);
            }
        }
        if(two>upper || two>lower || 2*two+one!=lower+upper) return vector<vector<int>>();
        auto iter=st.begin();
        for(int i=0;i<upper-two;++i){
            res[0][*iter]=1;
            ++iter;
        }
        while(iter!=st.end()){
            res[1][*iter]=1;
            ++iter;
        }
        return res;
    }
};
```
