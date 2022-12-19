
代码思路：
1. 遍历string，利用给定数组逐一进行统计。
2. 根据相关的要求，进行增加行数。
3. 创建返回数组。



# 代码：
```
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int i, 
        j,  
        eachrow = 0,
        numberoflines = 0,
         *returnarra = malloc(sizeof(int)* 2);

    while(*S != '\0'){
       if(eachrow + widths[*S - 'a'] > 100){
            numberoflines = numberoflines + (int)((eachrow + widths[*S - 'a'])/100);
            eachrow = 0;
        }
        eachrow += widths[*S - 'a'];
        S++;
    }

    
    if(eachrow > 100){
            numberoflines = numberoflines + (int)(eachrow/100);
            eachrow %= 100;
    }else if(eachrow > 0){
        numberoflines++;
    }
    
    *returnSize = 2;
    returnarra[0] = numberoflines;
    returnarra[1] = eachrow;
    return returnarra;
}

```

