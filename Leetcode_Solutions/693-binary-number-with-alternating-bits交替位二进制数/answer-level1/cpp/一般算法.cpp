
// ### 代码

// ```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n!=0)
        {
            if(n%2==(n>>1)%2) return false;
            n>>=1;
        }
        return true;
    }
};
// ```