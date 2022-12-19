## 一、开门见山，先沉痛小结
C语言不是python，不要乱用`""`代替`''`；
如果要用`strlen()`，请确保字符数组是以`'\0'`结尾，并注意是**单**引号杠零。
(习惯性给字符数组加上`'\0'`结尾貌似是个好习惯)

## 二、程序中给字符数组以`"\0"`(双引号杠零)结尾的情况
这种情况真是要多诡异就有多诡异。

### 解题思路
按行存入结果数组，思路很简单。

不过编程时又遇到了heap buffer overflow的错误，这次的错误只加了4行就解决了：
```c
    printf("第三个for，result[%d]=%c\n", 1, s[i]);

    ...

    for(int i=0;i<strlen(result);i++){  
        printf("result[%d]=%c\n", i, result[i]);
    }
```
对你没看错，就是这四行看上去没有任何卵用的语句，具体的添加位置在下述代码中注释了，如果有大神能说明为什么，感激不尽！


### 代码

```c
#include<string.h>

char * convert(char * s, int numRows){
    int length = strlen(s);
    char * result = (char *)malloc(sizeof(char) * (length + 1));    // 给'\0'留个位置
    
    int i, j = 0;
    if(numRows==1)return s;
    if(strlen(s)<=numRows)return s;

    for(i=0;i<length;i+=(2*(numRows-1))){
        result[j++] = s[i];
    }

    for(int row=1;row<numRows-1;row++){
        for(i=0;i<length;i+=(2*(numRows-1))){
            if(i-row>=0&&i-row<length){
                result[j++] = s[i-row];
            }
            if(i+row<length&&i+row>=0){
                result[j++] = s[i+row];
            }
        }
        if(i-row<length&&i-row>=0){
            result[j++] = s[i-row];
        }
    }
    
    for(int i=numRows-1;i<length;i+=(2*(numRows-1))){
        result[j++] = s[i];
        printf("第三个for，result[%d]=%c\n", j-1, s[i]);  // 不加这行会报错，为什么？？？这行的本来是用来debug的，最后发现反而被它左右着提交情况
    }

    result[j] = "\0";   // 这就是我说的用双引号作为数组结尾的地方。

    for(int i=0;i<strlen(result);i++){  // 不加这三行也会报错，为什么？？？同上，本来也是用来debug的，最后发现删了反而出错
        printf("result[%d]=%c\n", i, result[i]);
    }

    return result;
}
```

## 三、程序中给字符数组以`'\0'`(单引号杠零)结尾的情况
只需要改正一行：

```c
    ...

    result[j] = '\0';

    ...
```
然后把上文中提到的四行删掉，就不会出问题了。不仅如此，运行时间少了2/3.

## 四、再次沉痛小结
C语言不是python，不要乱用`""`代替`''`。