### 解题思路
基本思路就是判断log3n是不是整数
但是，C语言math.h中log的返回值为double型，显然无法判断是不是整数
故调整思路，改为把res = log3n强制转换成整形，然后判断pow(3, res) == n
#### 注
log3n 由换底公式 log(n)/log(3) 得
以下是直接按思路来的代码，emmmm，WA了
```c
bool isPowerOfThree(int n){
    if(n == 0) return false;

    if(pow(3, (int)(log(n)/log(3))) == n) return true;
    else return false;
}
```
WA的原因其实很简单，浮点型并不精确，存在浮动，然后强制转换(int)是截断取整
故如果存在结果应该是true，而由于浮点型的不精确，结果偏小，强制转换之后，res比实际小1，然后pow(3, res)就会不等于n，导致出错
#### 解决方案
在log(n)/log(3)后面加上一个浮点数(我加的是0.001，随手打的)，double型的精确度有15~16位，而int型的范围之后10位，所以即使结果整数部分能达到int的最大值(本题中不会达到)，还能有5-6位比较精确的数，在这个范围内加上一个很小的数，使结果不至于偏小即可(加上的数尽量小一些，防止出现res精确值很接近整数的情况，会导致错误，本题中应该也不会出现这种情况……哈哈^_^)……
有理解错误或者片面的地方请大佬指正……^_^……
### AC代码
```c
bool isPowerOfThree(int n){
    if(n == 0) return false;

    if(pow(3, (int)(log(n)/log(3) + 0.001)) == n) return true;
    else return false;
}
```