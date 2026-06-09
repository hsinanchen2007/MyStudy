判断单调递增数字，一遍过。思路：设当前数字长度为m,从低向高位检查，如果当前数字是递增的，返回；如果不是，就把低位n为都变成9，高m-n位数字的大小要减1，
保证变化后的数字不大于变化前的数字，n的变化从1到m变化。
```
class Solution {
public:
    bool isIncrease(int num){
        string temp = to_string(num);
        char c = temp[0];
        for(int i = 1 ; i < temp.size() ; i++){
            if(c > temp[i])
                return false;
            c = temp[i];
        }
        return true;
    }
    int nine(int length){
        string ans = "";
        while(length--)
            ans+='9';
        return atoi(ans.c_str());
    }
    int monotoneIncreasingDigits(int N) {
        if(isIncrease(N))
            return  N;
        int cir = 1;
        int ans;
        while(1){
            int nowDi = pow(10,cir);
            int t1 = N/nowDi;
            int t2 = N%nowDi;
            t1--;
            ans = t1*nowDi+nine(cir);
            if(isIncrease(ans))
                break;
            cir++;
        }
        return ans;
    }
};
```
