### 解题思路
1、统计字字符串中各个字符出现的次数
2、出现次数最多的字符的数量必须满足n < (length + 1) / 2
3、插桩，首席将出现次数最多的字符插入数组偶数位置，如果没有到达尾部，继续插入其它字符，直到数组尾部。
4、将为插入完成的字符插入数组奇数位置，直到完成。

### 代码

```c
char * reorganizeString(char * S){
    int a[26] = {0};
    char *p = S;
    while(*p != '\0'){
        int index = *p - 'a';
        a[index] += 1;
        p++;
    }

    int i = 0;
    int len = strlen(S);
    while(i < 26){
        if(a[i++] > (len + 1) / 2)
            return "";
    }

    char *res = (char*)malloc((len + 1) * sizeof(char));
    i = 0;
    int max = 0;
    int index = 0;
    while(i < 26){
        if(max < a[i]){
            max = a[i];
            index = i;
        }

        i++;
    }


    int start = 1;
    int end = 0;
    a[index] = 0;
    while(max > 0){
        res[end] = index + 'a';
        end += 2;
        max--;
    }

    i = 0;
    while(i < 26){
        if(a[i] > 0){
            int j = 0;
            while(j < a[i]){
                if(end < len){
                    res[end] = i + 'a';
                    end += 2;
                    j++;
                }else{
                    res[start] = i + 'a';
                    start += 2;
                    j++;
                }
            }
        }
        i++;
    }

    res[len] = '\0';
    return res;
}
```