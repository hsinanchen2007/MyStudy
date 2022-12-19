源码及解法说明：

```
#include<iostream>
using namespace std;


class Solution{
public:

    // 方法1：暴力法，需要两个循环，时间复杂度近似为 O(n^2)，n为num长度。
    int addDigits1(int num){
        int sum;
        while(num >= 10){
            sum = 0;
            while( num ){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    // 方法2: 总结规律法。 时间复杂度为O(1)
    // 设三位数 n = 100a + 10b + c 则 n - ( a+b+c) = 99a + 9b 也就是说每次n的各位求和结果与原n相比，
    // 都减少了9的倍数（它俩的差是9的倍数），所以n对9取余的结果就是所求结果。
    // n为其他位数时等同，注意 n > 0 且 n % 9 == 0 时，结果应为9
    int addDigits2(int num){
        int res = num % 9;
        if( res == 0 && num > 0)
            return 9;
        else
            return res;
    }

};
int main(){
    Solution s;
    int n;
    while( cin >> n ){
        cout << s.addDigits2(n) << endl;
    }
    return 0;
}

```