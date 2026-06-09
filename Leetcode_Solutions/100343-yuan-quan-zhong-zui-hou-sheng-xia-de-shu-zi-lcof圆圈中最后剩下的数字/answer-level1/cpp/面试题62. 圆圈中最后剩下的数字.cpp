```cpp
//1. 数学推导  动态规划
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1)
            return -1;
        if (n == 0)
            return 0;
        int f = 0;
        for (int i = 2; i <= n; i++)
            f = (f + m) % i;    //  动态规划解法中 % 的是 i 不是 n
        return f;
    }
};

// //1.1 数学推导  递归
// class Solution {
// public:
//     int lastRemaining(int n, int m) {
//         if (n < 1 || m < 1)
//             return -1;
//         if (n == 1)
//             return 0;
//         return (lastRemaining(n-1, m) + m) % n;
//     }
// };



// // 2. list模拟，超时
// class Solution {
// public:
//     int lastRemaining(int n, int m) {
//         list<int> list;
//         for (int i = 0; i <= n-1; i++)
//             list.push_back(i);  

//         auto p = list.begin();
//         while (list.size() > 1) {
//             for (int i = 0; i < m - 1; i++) {
//                 p ++;
//                 if (p == list.end()) p = list.begin();
//             }
//             auto tmp = p++;
//             list.erase(tmp);
//             if (p == list.end()) p = list.begin();
//         }   
//         return *list.begin();   
//     }
// };
```