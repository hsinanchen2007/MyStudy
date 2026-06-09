### 解题思路
整个思路就是用采用sprintf函数先把整型转化成字符串，然后尽量用存储换内存上的优化。开始溢出处理没有考虑整型反转后的有限结果范围，执行用时高达8ms，考虑到有限范围稍加优化就只有4ms了

### 代码

```c
#include <stdio.h>

int reverse(int x){
    char numStr[12];
    int ret=0;
    sprintf(numStr,"%d",x);
    int MS_ABS = 0, minesFlag = 0;
    if(numStr[0] == '-'){
        minesFlag = 1;
        MS_ABS++;
    }
    for(int i=11;i>=MS_ABS;i--){
        if(ret>=214748364){//溢出处理，对于多数x不成立所以分层冗余判断以加快执行速度；
            if((ret>214748364) || (ret==214748364) && (numStr[i]>'1'))//由于输入x的局限，只要考虑部分情况
                return 0;
        }
        ret *= 10;
        switch(numStr[i]){
            // case '0':
            //     ret += 0;
            //     break;
            case '1':
                ret += 1;
                break;
            case '2':
                ret += 2;
                break;
            case '3':
                ret += 3;    
                break;            
            case '4':
                ret += 4;
                break;
            case '5':
                ret += 5;
                break;
            case '6':
                ret += 6;
                break;
            case '7':
                ret += 7;    
                break; 
            case '8':
                ret += 8;
                break;
            case '9':
                ret += 9;     
                break;
        }
    }
    if(minesFlag){
        ret = -1 * ret;
    }
    
    return ret;
    
}
```