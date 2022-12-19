![QQ截图20200301175630.jpg](https://pic.leetcode-cn.com/7dbfbcd7c8f92ba3d3831f7db2dd7d5a7a6c844265b9b3e218cb365969b5ddd8-QQ%E6%88%AA%E5%9B%BE20200301175630.jpg)

### 代码

```c
int findNthDigit(int n){
    int num =9; // 记录当前位数一共有多少个数
    int bit = 1; // 记录当前位数
    int tar = 0; // 目标值
    int standrd = num * bit; // 记录当前位数的数字总数
    while(n>standrd) // 当n大于当前位数的数字总数时
    {
        n = n -standrd;  // n减去当前位数的数字总数
        bit++; // 当前位数加一
        if(bit == 9) // 如果位数到了9位，跳出循环，若无次步骤，当n足够大时，下面语句会产生溢出
            break;
        num =num * 10; // 更新当前位数一共有多少个数
        standrd = num * bit;  // 更新当前位数的数字总数
    }
    tar = (int)pow(10,(bit-1)) * 1; // 这时n表示bit位数的第几个数字，首先使位数同步
    if(tar == 1) // 如果为1位
    {
        return n;// 直接返回n   
    }
    else
    {
        tar = (n-1)/bit + tar; // 找到第n个数字所在的那个bit位数
        char s[11]; 
        sprintf(s,"%d",tar); // 将其转化为字符串
        tar = (int)s[(n-1)%bit] -48; // 得到目标数字
        return tar; // 返回
    }
}
```