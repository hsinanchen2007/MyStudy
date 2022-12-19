```cpp
// // 动态规划
// class Solution {
// public:
//     int cuttingRope(int n) {

//         if (n == 2)  // n==2 和 n==3是特殊情况，分割后乘积小于自身，但根据题意不得不分割，因此单独讨论
//             return 1;
//         if (n == 3)
//             return 2;
        
//         // 往下的 n >= 4
//         vector<int> memo(n+1, 0); 
//         memo[1] = 1; 
//         memo[2] = 2; //当n>=4, 保存子问题到最优解，分割后得到的长度为2和为3的绳子，可以不分割，所以memo值为自身
//         memo[3] = 3;

//         //f(i) = max{ f(j) * f(i-j) }  1 <= j <= i/2 
//         for (int i = 4; i <= n; i++)     
//             for (int j = 1; j <= i/2; j++) {
//                 memo[i] = max(memo[i], memo[j]*memo[i-j]);
//             }

//         return memo[n];       

        
//     }
// };


//贪婪算法
class Solution {
public:
    int cutRope(int n) {

        if (n == 2)  // n==2 和 n==3是特殊情况，分割后乘积小于自身，但根据题意不得不分割，因此单独讨论
            return 1;
        if (n == 3)
            return 2;
        
        int time3 = n / 3;   //n >=5  时应多剪长度为3的绳子
        if (n - 3 * time3 == 1)
            time3 --;
        
        int time2 = (n - 3 * time3) / 2;

        return pow(2, time2) * pow(3, time3);            
    }
};
```