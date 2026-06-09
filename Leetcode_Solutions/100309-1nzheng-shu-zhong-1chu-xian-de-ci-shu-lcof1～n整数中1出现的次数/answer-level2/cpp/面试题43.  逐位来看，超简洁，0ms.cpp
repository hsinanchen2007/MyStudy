// ```cpp

// //1. 逐位来看，统计1出现在每一位上的次数
// class Solution {
// public:
//     int countDigitOne(int num) {   // 3141592
//         int res = 0;
//         for (long long m = 1; m <= num; m *= 10) {
//             int a = num / m;  // m=100, a=31415, 看百位上的数字，此时是5
//             int b = num % m;  // m=100, b=92
//             // 拿到百位上的数字，分三种情况 >1 =1 =0
//             if (a%10 > 1) 
//                 res += (a/10 + 1) * m;
//             else if (a%10 == 1)
//                 res += a/10 * m + b + 1;
//             else
//                 res += a/10 * m;
//         }
//         return res;
//     }
// };


//1. 等同于上面的，更简洁的写法，三个条件统一起来
class Solution {
public:
    int countDigitOne(int num) {   // 3141592
        int res = 0;
        for (long long m = 1; m <= num; m *= 10) {
            int a = num / m;  // m=100, a=31415, 看百位上的数字，此时是5
            int b = num % m;  // m=100, b=92
            // 拿到百位上的数字，分三种情况 >1 =1 =0
            // if (a%10 > 1) 
            //     res += (a/10 + 1) * m;
            // else if (a%10 == 1)
            //     res += a/10 * m + b + 1;
            // else
            //     res += a/10 * m;
            
            res += (a+8)/10*m + (a%10 == 1)*(b + 1);  //等价于三个条件
        }
        return res;

    }
};


// // 2. 🔥稍复杂
// class Solution {

// int f_table[10] = {0};
// // f(1) = 1;
// // f(2) = 20;
// // f(3) = 300;
// // f(4) = 4000;
// // f(5) = 50000;
// // f(6) = 600000;
// // f(7) = 7000000;
// // f(8) = 80000000;
// // f(9) = 900000000;

// private:
//     void set_table() {
//         for (int i = 1; i < 10; i++) 
//             f_table[i] = f_table[i-1] * 10 + pow(10, i - 1);
//     }

// public:
//     int countDigitOne(int num) {
//         set_table();
//         stack<int> s;
//         int sum = 0;
//         int tmp = num;
//         while (tmp) {
//             s.push(tmp % 10); 
//             tmp = tmp / 10;                     
//         }
//         while (!s.empty()) {
//             int x = s.top(); // 得到最高位数字
//             int weishu = s.size();
//             s.pop();
//             if (x > 1) // 分三种情况 >1 =1 =0
//                 sum += pow(10, weishu - 1);
//             else if (x == 1)
//                 sum += num % int(pow(10, weishu - 1)) + 1;
//             else
//                 continue;
//             sum += f_table[weishu - 1] * x;
//         }

//         return sum;

//     }
// };

// ```