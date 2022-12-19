```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend ^ divisor) < 0;
        
        int ans = 0;
        int cnt = -1;
        
        //考虑到2^31会超出，所以转换成负数来计算；
        if (dividend>0) dividend = -dividend;
        if (divisor>0) divisor = -divisor;
        
        int temp = divisor;
        
        while (dividend<=temp) {
            if (dividend<=divisor) {              
                ans += cnt;
                dividend -= divisor;

                cnt += cnt;
                if (divisor < -1073741824) break;
                divisor += divisor;     
            }       
            else { //
                divisor = temp;
                cnt = -1;
            }
            
        }

        return  sign?ans:-ans;

    }
};

