### 解题思路
检查每个字符串的第一个字符，如果相同则写入结果字符数组；检查每个字符串的第二个字符，如果相同则写入结果字符数组……直到不相同或者遍历到某一个串的结尾.

时间复杂度表现中下，空间复杂度表现中上。

【注意事项】
实现过程中唯一需要注意的就是字符数组的访问不要越界。
本程序的易错点就是，当传入二维数组指针`strs`为空的时候，如果访问`strs[0][0]`就会发生错误，解决这个错误的方法是将传入为空的情况单独处理。

### 代码

```c
int checkIfEnd(char ** strs, int sub, int strsSize){  // 检查当前下标是否已经是某一串的结尾
    for(int i=0;i<strsSize;i++){
        if(strs[i][sub]=='\0'){
            return 1;
        }
    }
    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int subscript = 0;
    int breakFlag = 0;
    char * result = (char *)malloc(sizeof(char) * (strsSize + 5));

    // 单独处理传入为空的情况
    if(strsSize==0){    // 易错部分，不加这个会发生下标越界。具体原因是我的程序总是会访问strs[0][0]，即便它是空的
        result = "";
        return result;
    }

    while(true){
        if(checkIfEnd(strs,subscript,strsSize)==1)break;
        for(int i=0;i<strsSize;i++){
            if(strs[i][subscript]!=strs[0][subscript])breakFlag = 1;
        }
        if(breakFlag==1)break;
        else{
            result[subscript++] = strs[0][subscript];
        }
    }
    result[subscript] = '\0';
    return result;
}
```