### 解题思路
（1）处理特殊情况，即只有一个编码的情况
（2）统计0之前连续的1的个数
（3）偶数个1返回true，奇数个1返回false

### 代码

```c
bool isOneBitCharacter(int* bits, int bitsSize){
    int i,flag=0;
    if(bitsSize==1){
        if(bits[0]==1) return false;
        else return true;
    }
    for(i=bitsSize-2;i>=0;i--){
        if(bits[i]==1) flag++;
        else break;
    }
    if(flag%2==0) return true;
    else return false;
}


```