以 column 来记录所有上方行已放置的皇后导致当前行格子不可用的集合，所在列如果放了皇后，则当前行格子对应的位置为 1，否则为 0，同理,以 pie（撇，左斜线） 记录所有已放置的皇后左斜方向导致当前行格子不可用的集合， na（捺，右斜线） 表示所有已放置的皇后右斜方向导致当前行不可用的集合。

参考：[**图解算法：摘取位运算的王冠「八皇后问题**」！](https://mp.weixin.qq.com/s?__biz=MzUyNjQxNjYyMg==&mid=2247487922&idx=2&sn=638d54092c46d25411623132bc4002c7&chksm=fa0e7e33cd79f72509e28a0cf59fede4a112946864965ca6494dcf807c38a93391fe30a783c1&scene=126&sessionid=1586049720&key=861420a46a8ac7f720cea5a6f33ca00880ceaed8db451ad33843dcb7ca1c4561ebba6ea2f395ccaad0e16cb42d0c575483361df2fbcc1d1e4038dd7a40f1d4484fd797900b07e66167af3c71d55edc10&ascene=1&uin=MTg4NzM5NTEzMg%3D%3D&devicetype=Windows+10&version=62080079&lang=zh_CN&exportkey=AwIOXG3U6ub%2FsOJaaAo7Flo%3D&pass_ticket=HQzkiJb5mnK4NEhIEVKirhMzPhRFEe033IaDGrPQOwl7qY8KTz9%2BVKddWUwKVB3d)

```
class Solution {
public:
    void backtrack(vector<vector<string>> &res, vector<string> state, int N, int colum, int pie, int na){
        if(state.size()>=N){
            res.push_back(state);
            return;
        }
        int bits=(~(colum|pie|na)) & ((1<<N)-1);
        while(bits>0){
            int p = bits&-bits;
            string tmp="";
            for(int i=0;i<N;i++){
                if((1<<i)==p){
                    tmp="Q"+tmp;
                }
                else{
                    tmp="."+tmp;
                }
            }
            state.push_back(tmp);
            backtrack(res, state, N, colum|p, (pie|p)<<1, (na|p)>>1);
            state.pop_back();
            bits = bits&(bits-1);
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> state;
        backtrack(res, state, n, 0, 0, 0);
        return res;
    }
};
```
