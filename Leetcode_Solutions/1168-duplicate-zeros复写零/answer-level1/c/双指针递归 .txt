这个方法跑出来大概16ms，高于C提交的98.02%。看见好像没有人放递归的代码，就贴出来。如果有不简洁或者疏漏的地方，也希望大佬不啬赐教！

- 用两个指针pwrite和pread分别记录当前递归深度扫描读取元素的位置、要写入的位置
 1. 若读入位指针pread到达末尾，递归结束
 2. 若读入位指针pread未到达末尾，则对pread和pwrite进行移动递归，pwrite的偏移量可能为1或2，由pread元素决定
 3. 若读入位pread元素为0，则需要从pwrite开始写入**至多两个0**（如果超过了数组边界则停止写入）
 4. 若读入位pread元素不为0，则把该元素写入pwrite指向位置

- 因为多出的复写0会覆盖有效的元素，所以需要从后往前改写数组
- 所以判断入读位情况后**先进行递归入栈，再进行当前的写入**，本质上就是从末尾开始改写数组


```
void duplicateZeros(int* arr, int arrSize){

    void rewrite( int pwrite, int pread, int *arr, int Size );

    rewrite( 0, 0, arr, arrSize );

    return arr;
}

void rewrite( int pwrite, int pread, int *arr, int Size )
{
    if( pread == Size )
        return ;
    
    if( arr[ pread ] == 0 ){
        rewrite( pwrite + 2, pread + 1, arr, Size );
        if( pwrite <= Size - 1 )
            arr[ pwrite ] = 0;
        if( pwrite <= Size - 2 )
            arr[ pwrite + 1 ] = 0;
    }
    else{
        rewrite( pwrite + 1, pread + 1, arr, Size );
        if( pwrite <= Size - 1 )
            arr[ pwrite ] = arr[ pread ];
    }
}
```

需要注意的点：
1. 复写的0可能溢出
2. 递归的边界

