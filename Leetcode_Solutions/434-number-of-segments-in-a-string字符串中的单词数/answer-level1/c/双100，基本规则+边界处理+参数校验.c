
### 解题思路
1，单词基本规则：遍历字符串，看看有多少S[i] ！= 空格 并且S[i+1] = 空格；count
2, 边界处理：最后一个字符是空格那么计数不变，不是空格那么计数+1；count++
3、入参校验：空串儿，全是空格（bool bFind标识）

### 代码

```c
int countSegments(char * s){   
    int len = strlen(s);
    if(!len)
        return 0;

    int count = 0;
    bool bFind = false;

    for(int i = 0; i < len - 1; i++){
        if((s[i] != ' ') && (s[i+1] == ' ')){
            count++;
            bFind = true;
        }
    }

    printf("%d %d\n", bFind, count);

    if((!bFind) && (s[len - 1] != ' ')){
        //printf("%d, %d\n", len, *(s + len));
        
        bFind = true;
        printf("%d\n", bFind);
    }

    count = s[len - 1] == ' ' ? count : count+1;

    return bFind? count : 0;
}
```