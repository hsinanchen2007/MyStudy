
寻找其中规律：
    n = 1， f = 1
    n = 2,  f = 2
    n = 3,  f = 3
    得到f(n) = f(n - 1) + f(n - 2)
`    
    class Solution {
    public:
        int climbStairs(int n) {
            if(n == 1) return n; 
            int f[2] = {1, 2};
            
            for(int i = 2; i < n; i++)
            {
                int temp = f[1];
                f[1] = f[0] + f[1];
                f[0] = temp;
                
                cout << f[0] << " " << f[1] << endl;
            }
            return f[1];
        }
    };`

