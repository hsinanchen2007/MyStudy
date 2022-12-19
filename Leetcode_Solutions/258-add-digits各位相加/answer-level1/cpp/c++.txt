![3V\]{`ICKW)MCLQZ\]E\]T2S`X.png](https://pic.leetcode-cn.com/4df24380bb450ea91876ab0842743500e1d8c91d9cb6b1bdc39dd683b7b895df-3V%5D%7B%60ICKW\)MCLQZ%5DE%5DT2S%60X.png)


##解题思路：
//1.re存储每一次拆解后的各个位之和
//2.当re<10时，返回re；否则将re的值传给num，re置为0，再次计算各个位的和

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) 
    {
        int re=0;
        if(num<10)
        {
            return num;
        }
        while(num)
        {
            re+=num%10;
            num=num/10;
            if(num==0)
            {
                if(re<10)
                {
                    return re;
                }
                else
                {
                    num=re;
                    re=0;
                    continue;
                }
            }
            
        }
        return re;
    }
};
```