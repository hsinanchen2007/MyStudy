```c++
class Solution {
public:
    int findNthDigit(int n) {
        long long pw=1;//数量级
        long long we=1;//宽度
        long long cnt=0;//位数积累
        int num;
        int pos;
        int left;
        while(cnt+9*pw*we <n )
        {
            cnt+=(9*pw*we);
            pw*=10;
            ++we;

        }
        /* num //最后一个数字
         left //在最后一个数字钟的位数（高到低）
        pos = we-left;//转换为低到高
        */
        if((n-cnt)%we==0)
        {
            num = pw+(n-cnt)/we-1;
            left=we;
            pos = we-left+1;
        }
        else
        {
            num = pw+(n-cnt)/we;
            left = (n-cnt)%we;
            pos = we-left+1;
        }
    

        while(pos>1)
        {
            num/=10;
            --pos;
        }
    // cout <<"ret="<<num%10<<endl;
        return num%10;

    }

};
```