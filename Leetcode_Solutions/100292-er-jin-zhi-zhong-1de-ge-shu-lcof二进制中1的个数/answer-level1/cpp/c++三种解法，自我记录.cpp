位运算包括5种
- 与
- 或
- 异或
- 左移
- 右移

对于左移（<<）n位，即把左边n个数去掉，在右边补上n个0
对于右移（>>）n位，无符号数而言，去掉右边n个数，左边补上n个0；有符号数而言，去掉右边n个数，左边补上n个符号位


解法一：将n不断右移1位，每右移一次，则判断最右边是不是1，并统计1的个数
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n<=1) return n;

        int count=0;
        for(int i=32;i>0;i--){
            //判断最右边一位是不是1，即和1相与，结果为1，计数器加1，结果为0，计数器不加
            if(n&1) count++;
            //右移1位，将已经判断的位去掉，同时把下一位放到最右边，以便下次判断
            n=n>>1;
        } 

        return count;
    }
};
```

解法二：不对n进行右移操作，而是将判断用的1进行左移
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n<=1) return n;

        int count=0;
        unsigned int flag=1;
        for(int i=32;i>0;i--){
            if(n&flag) count++;
            flag=flag<<1;
        } 

        return count;
    }
};
```

解法三：n-1，可以把n中从右数第一个1变为0，且1后面的0全变为1。此时n&(n-1)的结果是n中右数第一个1变为了0，其余位保持不变。
例：
1100-1=1011
1100&1011=1000
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n<=1) return n;

        int count=0;
        while(n){
            count++;
            n=n&(n-1);
        } 

        return count;
    }
};
```


