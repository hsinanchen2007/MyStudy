执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :33 MB, 在所有 java 提交中击败了15.12%的用户

```
class Solution {
    public int countDigitOne(int n) {
        int k, t, first;

        if(n < 1)
            return 0;
        k = log10(n);
        t = pow10(k);
        first = n / t;
        if(first == 1)
            //以123为例,1的个数 = 100~123中首位1的个数 + 0~99中1的个数 + 100~123后两位中1的个数
            return n % t + 1 + countDigitOne(t - 1) + countDigitOne(n % t);
        //以789为例,1的个数 = 100~199中首位1的个数 + X00~X99中1的个数(X:0~6) + 700~789后两位中1的个数
        return t + first * countDigitOne(t - 1) + countDigitOne(n % t);
    }

    private int log10(int n){
        int answer;

        answer = -1;
        while(n != 0){
            n /= 10;
            answer++;
        }
        return answer;
    }

    private int pow10(int n){
        int answer;

        answer = 1;
        while(n != 0){
            answer *= 10;
            n--;
        }
        return answer;
    }
}
```
