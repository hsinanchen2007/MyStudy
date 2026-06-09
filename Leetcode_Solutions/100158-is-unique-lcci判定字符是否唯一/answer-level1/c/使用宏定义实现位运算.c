本题虽没有明确说明，但是其测试用例均为小写字母，总共为26种字符，使用一个整形变量，则其中的26位可以用来表示各字符的状态。
对字符串进行一趟扫描，对于每个字符，每次将该字符的对应位加一，然后判断，若该位为1，说明该字符是第一次出现，若该位为零，说明该字符是第二次出现，此时返回false。若扫描结束后没有返回false，则返回true。
使用C语言的宏定义设计第n位的不带进位的加法函数`#define ADDBIT(x, n) ( (x) ^= ( 1 << (n) ) )`
以及读取第n位的值的函数`#define GETBIT(x, n) ( ( (x) >> (n) ) & 1 )`

```
#define ADDBIT(x, n) ( (x) ^= ( 1 << (n) ) )
#define GETBIT(x, n) ( ( (x) >> (n) ) & 1 )
bool isUnique(char* astr){
    int flag = 0;
    while(*astr){
        ADDBIT(flag, *astr - 'a');
        if(!GETBIT(flag, *astr - 'a')){
            return false;
        }
        astr++;
    }
    return true;
}
```
