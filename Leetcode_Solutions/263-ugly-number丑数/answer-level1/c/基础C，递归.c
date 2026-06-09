### 解题思路
因为丑数是正数，所以先剥离一部分非正数；然后递归分离为2、3、5的质因数

### 代码

```c
bool isUgly(int num){
    if(num<1)  return false;
    if(num==1)  return true;
    if(num==2||num==3||num==5)  return true;
    if(num%2==0)  return isUgly(num/2);
    if(num%3==0)  return isUgly(num/3);
    if(num%5==0)  return isUgly(num/5);
    else return false;
}
```