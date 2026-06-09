方法1：最简单的思路
```
int* getRow(int rowIndex, int* returnSize){
    static int yangtri[34][34];//不加static的话，会出现**错误提示：**load of null pointer of type 'const int'
    *returnSize = rowIndex + 1;
    int i, j;
    for (i = 0; i <= rowIndex; i++)
        yangtri[i][0] = 1;
    for (i = 1; i <= rowIndex; i++)
        yangtri[i][i] = 1;
    for (i = 2; i <= rowIndex; i++){
        for (j = 1; j < rowIndex; j++){
            yangtri[i][j] = yangtri[i - 1][j - 1] + yangtri[i - 1][j];
        }
    }
    return yangtri[rowIndex];
}
```

在调用函数时，如果返回值如果是一个常量则没问题。如果返回值若为指针则可能会出现该错误，假如返回的指针地址指向函数内的局部变量，在函数退出时，该变量的存储空间会被销毁，此时去访问该地址就会出现这个错误。

解决办法有以下三种:
    
1. 返回的指针使用malloc分配空间
2. 将该变量使用static修饰 static修饰的内部变量作用域不变 但是声明周期延长到程序结束 即该变量在函数退出后仍然存在
3. 使用全局变量

**我用malloc分配空间来解决时一直有错，暂时还不知道问题所在，希望有心人在评论去附上解答，谢谢。**

方法2：简洁巧妙
```
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int *res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int i = 0; i < rowIndex + 1; i++){
        res[i] = 1;
        for (int j = i - 1; j > 0; j--){
            res[j] += res[j - 1];
        }
    }
    return res;
}
```
方法3：用公式
