### 解题思路
![深度截图_选择区域_20200313101715.png](https://pic.leetcode-cn.com/b1599522d92ae996948810d92c3a1d2ab7de3028f422eae22c7658e926684443-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200313101715.png)
主要思路用减法来代替除法，不过直接减会超时，所以我们每次 被除数-除数 之前都会将除数翻倍（就是左移1位）
直到被除数小于等于除数，然后再进行 被除数-除数 还有运用long long 来处理溢出问题

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dd=dividend,dr=divisor,sum=0;
        if(dividend==0)return 0;//除数为零
        
        if(dr==1)return dd;//被除数为-1或者1
        if(dr==-1){
            if(dd==-2147483648)return 2147483647;
            else return -dd;
        }
        dd=abs(dd);
        dr=abs(dr);
        
        while(dd>=dr){
            int i=1;
            //使divisor翻倍，减少‘-’运算的次数
            while(dd-(dr<<i)>=0){
                ++i;
            }
            --i;
            dd=dd-(dr<<i);
            sum+=1<<i;
        }
    
        if(dividend>0&&divisor<0||dividend<0&&divisor>0)return -sum;
        return sum;
    }
};
