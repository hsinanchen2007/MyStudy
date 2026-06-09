对宝石进行遍历，对每一种宝石直接在石头中计数，然后相加即可，用到了count函数
用时0s
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int sum=0;
        for(int i=0;i<J.size();i++){
            int temp=count(S.begin(),S.end(),J[i]);
            sum+=temp;
        }
        return sum;
    }
};