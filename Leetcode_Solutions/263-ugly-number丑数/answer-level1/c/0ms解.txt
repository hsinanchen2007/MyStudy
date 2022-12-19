若num为0，则返回false，若不为0，则循环整除2，3，5，最后结果如果是1则num是丑数。
```
bool isUgly(int num){
    if(num==0)
        return false;
    while(num%2==0)
        num/=2;
    while(num%3==0)
        num/=3;
    while(num%5==0)
        num/=5;
    return num==1;
}
```
