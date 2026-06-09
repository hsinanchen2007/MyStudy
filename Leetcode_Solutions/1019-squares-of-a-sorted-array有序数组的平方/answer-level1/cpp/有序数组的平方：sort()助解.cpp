简单思路：先平方，再排序输出
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &vec:A)
        {
            vec=vec*vec;
        }
        
        sort(A.begin(),A.end());
        
        return A;
    }
};