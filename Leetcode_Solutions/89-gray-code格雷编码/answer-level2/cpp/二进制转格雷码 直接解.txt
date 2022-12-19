/*
思路:二进制数转格雷码
即: G(n) = B(n+1) XOR B(n)
*/

    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res;
            int length = pow(2,n);
            for(int i=0;i<length;i++){
                // G(n) = B(n+1) ^ B(n)
                res.push_back( (i >> 1) ^ i );
            }
            return res;
        }
    };


![image.png](https://pic.leetcode-cn.com/e4d943c81dd6585db2c34a55e89d731eb915c05f7f48f1fc3bcb827fe4b1665c-image.png)
