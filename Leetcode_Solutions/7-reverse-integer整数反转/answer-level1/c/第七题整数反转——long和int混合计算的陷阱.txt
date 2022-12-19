### 注意事项
由于中间结果可能超过限制，所以定义变量`temp`为`long`型，同时注意：
```c
temp += ((long)abs(x % 10) * (exponent_num(count-i-1)));
```
这一行中`(long)`显得格外重要，因为`abs(x % 10)`和`(exponent_num(count-i-1))`都是`int`型，但两者相乘结果可能用`int`型装不下，而相乘之后的中间结果要和`temp`相加，在相加之前这个中间结果会进行“暂存”，如果不加`(long)`进行强制类型转换，这个中间结果就会被暂存到一个`int`型区域中，就会发生`signed integer overflow`。此处是将`abs(x % 10)`转换成`long`（而不是在`+=`后面加`long`，那样不会改变出错因素）即可，乘号右边没有转换是因为`long`乘`int`时，系统会自动将`int`转换为`long`。

题目已告之`int`范围是`-2^31~2^31-1`，所以最后几行：
```c
    if(temp<-(1024*1024*1024*2)||temp>(1024*1024*1024*2)-1)return 0;
    else{
        result = temp;
        return result;
    }
```
由于限制了超出`int`范围返回0，没超出范围才会进入`else`，所以在`else`中，不用担心`result = temp`会导致溢出。

### 代码

```c
int bitCount(int x){
    int count = 0;
    while(x!=0){
        x /= 10;
        count++;
    }
    return count;
}

int exponent_num(int exponent){
    int result = 1;
    for(int i=0;i<exponent;i++){
        result *= 10;
    }
    return result;
}

int abs(int x){
    if(x<0)return -x;
    else return x;
}

int reverse(int x){
    long temp = 0;
    int result;
    int count = bitCount(x);
    int i = 0;
    int sign = (x >= 0) ? 1 : 0;
    while(x!=0){
        temp += ((long)abs(x % 10) * (exponent_num(count-i-1)));    // 极为关键的一行，在正确的位置加上long类型转换才能避免signed integer overflow错误
        x /= 10;
        i++;
    }
    if(sign==0){
        temp *= -1;
    }
    
    if(temp<-(1024*1024*1024*2)||temp>(1024*1024*1024*2)-1)return 0;
    else{
        result = temp;
        return result;
    }
}
```