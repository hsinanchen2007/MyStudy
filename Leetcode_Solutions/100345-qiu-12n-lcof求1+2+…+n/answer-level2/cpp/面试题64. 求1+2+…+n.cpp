```cpp
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};


// class Temp {
// private:
//     static int N;
//     static int Sum;

// public:
//     Temp() { N ++; Sum += N; }
//     static void Reset() { N = 0; Sum = 0;}
//     static int GetSum() { return Sum;}
// };

// int Temp::N = 0;
// int Temp::Sum = 0;

// class Solution {
// public:
//     int sumNums(int n) {
//         Temp::Reset();
//         Temp * tmps = new Temp[n];
//         delete []tmps;
//         return Temp::GetSum();
//     }
// };

```