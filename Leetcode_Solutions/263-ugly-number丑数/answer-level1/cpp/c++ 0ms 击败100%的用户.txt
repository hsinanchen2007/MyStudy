class Solution {
public:
    bool isUgly(int num) {
        while(num!=1)
        {
            int t=num;
            if(num%2==0)num/=2;
            if(num%3==0)num/=3;
            if(num%5==0)num/=5;
            if(t==num)return false;***如果一趟下来num的值没变，则num无法被2,3,5整除***
        }   
        return true;
    }
};
***第一次写题解，写得不好还请见谅***