思路很简单，1.先找到比low大的，第一个顺序数。2.按顺序输出其他的，一个循环就ok。3.输出完本位次，需要进位就进位，进位需要一个循环。
主要难点1.怎么输出其他的 2.怎么进位
1.只要首数字+1，然后再到循环跑一下
2.将首数字变为1，然后将位数+1，再到循环跑一下



class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>vec;
        int n = 0; //记录low的位数
        int m = low; //记录首数字

        while( m >= 10){
            m = m/10;
            ++n;
        }
        //需要考虑直接就需要进位的 比如（790   2000）
        if(n + m >10){
            m = 1;
        }
        while( n <11){   
            while( n+ m <10){  //如果n+m>10,不可能有解
                int m1 = m;
                int p = 0; //记录符合的值
                for(int i = n;i>=0;--i){
                    p += m1*pow(10,i);
                    ++m1;
                }
                if( p >= low && p<= high){
                    vec.push_back(p);
                }
                if( p > high){
                    return vec;
                }
                ++m;
            }
            m =1;
            ++n;
        }
        return vec;
    }
};