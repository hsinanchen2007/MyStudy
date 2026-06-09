class Solution {
public:
    bool isPowerOfTwo(int n) {
        int tmp=1;
        while(tmp!=n){
            if(tmp>n||tmp>INT_MAX/2)
                return false;
            else
                tmp=tmp<<1;
        }
        return true;
    }
};