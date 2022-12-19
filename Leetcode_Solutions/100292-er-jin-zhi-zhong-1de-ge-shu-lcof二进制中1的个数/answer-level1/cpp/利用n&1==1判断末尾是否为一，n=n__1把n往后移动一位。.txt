class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=1;i<=32;++i){
            if(n&1==1) ++cnt;
            if(n<2) break;
            n=n>>1;
        }
        return cnt;
    }
};