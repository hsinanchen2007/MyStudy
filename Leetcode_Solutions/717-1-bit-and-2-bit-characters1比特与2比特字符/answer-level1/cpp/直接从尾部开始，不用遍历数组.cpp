```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(n>=2){
            if(bits[n-2]==1){
                int cnt=1;
                for(int i=n-3;i>=0;--i){
                    if(bits[i]!=1) break;
                    else cnt++;
                }
                return cnt%2==1?false:true;
            }
            else return true;
        }
        return true;
    }
};
```直接计算尾部连续的1的个数，当个数为奇数时，末尾的0必须与1结合；当为偶数时，0单列。