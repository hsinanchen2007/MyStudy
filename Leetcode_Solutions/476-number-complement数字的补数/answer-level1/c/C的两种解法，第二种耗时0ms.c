第一种是 非常直观的方法，就是依次看后一位是不是1，如果是就反转为0

```c
int findComplement(int num){

    int res = 0;
    int cnt = 0;
    int j = 0;
    while ( num != 0){
       cnt =  num & 0x1;
       res = res +  (1-cnt) * pow(2, j++);
       num >>= 1;
    }
    return res;
}
```

第二种就是按照定义，对于1011而言，补位就是1111 - 1011 = 0100

```c
int findComplement(int num){
    long temp = 1;
    while (num >= temp){
        temp <<= 1;
    }
    return (temp - 1 - num);
}
```

第二种方法耗时0ms