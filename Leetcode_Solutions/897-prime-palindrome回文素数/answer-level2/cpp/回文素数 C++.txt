![回文素数leetcode.png](https://pic.leetcode-cn.com/3408d8c989c873e71ce67b42b31a780eaea871e46386b08efc1b121834282239-%E5%9B%9E%E6%96%87%E7%B4%A0%E6%95%B0leetcode.png)

**题目**：求出大于或等于 N 的最小回文素数。

**提示**：

    1 <= N <= 10^8
    答案肯定存在，且小于 2 * 10^8。
- 根据提示，答案长度最长为 9 位。

- 暴力法会超时，因此可以先构建回文数，再判断是不是素数。

- 构建回文数可以从 N 的当前长度开始：比如 N=123, 可以从长度为 3 的 101 开始构建。

- 构建回文数可以**忽略偶数长度**，因为偶数长度的回文数，奇数位上数字之和=偶数位上数字之和，是11的倍数，所以不是素数。
比如 131131, 1+1+3 = 3+1+1, 所以 131131 是 11 的倍数，不是素数。

- 构建回文数可以**从外到内，从小到大**构建，这样可以保证结果**递增**。从外到内**递归**实现。比如长度为5:
10001, 11011, 11111, 11211, ..., 11911, 
12021, 12121, ..., 12921,
......
19091, 19191, ..., 19991,
20002 //忽略
30003, 31013, ......
......
99999

- **最外层数字肯定不是 0**, 因为最高位不是 0 ; 如果**个位的数字**是 **2 的倍数或者是 5**, 那肯定不是素数，可以忽略。

# 程序

```
class Solution {
public:
    int primePalindrome(int N) {
        for(int i=N;i<=11;i++)//小于10直接判断；11 要单独判断，因为偶数长度的回文数，奇数位上数字之和=偶数位上数字之和，是11的倍数，所以不是素数
            if(isPrime(i))
                return i;
        bool found=false;
        int m=N, l=0;
        while(m){//找到N的长度
            m/=10;
            l++;
        }
        for(int i=l/2;i<5;i++){//从N的长度的一半开始构建回文数，长度最多是9，因为题目说答案小于 2 * 10^8
            string str(i*2+1,'0');//奇数长度，l*2+1 ~ 9
            makePalindrome(N, str, i*2, 0, i*2, found);
            if(found)
                return strToInt(str);
        }
        return -1;
    }

    void makePalindrome(const int &N, string &str, const int len, int l, int r, bool &found){//从左右两端向里面构建长度为 len+1 的回文数
        if(found)
            return;
        if(l>r){//构建完回文数，判断是不是素数
            int m=strToInt(str);
            found = (m>=N) && isPrime(m);
            return;
        }
        bool begin = (r==len);//判断是不是回文数最外面一位
        for(int i=0;i<10;i++){//每一位从0到9遍历
            if(found)
                return;
            if( begin && (i%2==0||i==5) )//个位是2的倍数或者5肯定不是素数
                continue;
            str[l]=str[r]='0'+i;
            makePalindrome(N,str,len,l+1,r-1,found);//从外到内，从小到大构建回文数
        }
    }

    bool isPrime(int x){
        if(x<=1)
            return false;
        for(int i=2;i*i<=x;i++)
            if(x%i==0)
                return false;
        return true;
    }

    int strToInt(const string &s){
        int x=0;
        for(int i=0;i<s.size();i++)
            x=(x<<3)+(x<<1)+(s[i]-'0');// x*8 + x*2 = x*10
        return x;
    }
};
```
