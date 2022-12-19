 
    class Solution {
        public int cuttingRope(int n) {
            if(n <= 3) {
                return n - 1;
            }
            int p = n % 3;    // 0 1 2
            int q = n / 3;
            
    //      将上一个题改造一下		
    //		if(p == 0) {
    //			return (int)Math.pow(3, q);
    //		}else if(p == 1) {
    //			return (int)Math.pow(3, q - 1) * 4;
    //		}else {
    //			return (int)Math.pow(3, q) * 2;
    //		}
            
            long res = 0;
            if(p == 0) {
                res = 3;
            }else if(p == 1) {
                res = 4;
            }else {
                res = 6;
            }
            
            q = q - 1;
            while(q > 0) {
                res = (res * 3) % 1000000007;
                q--;
            }
            return (int)res;
        }
    }