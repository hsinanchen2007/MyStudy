### 解题思路
1、首先判断下入参有效性，两个入参全为NULL返回true，单个入参为NULL或入参长度不一致均返回false
2、初始化两个hash表，hashS和hashT
   其中hashS是用来表示该字符是否已经映射过
       hashT是用来表示字符映射关系的
3、根据映射关系将t的值进行替换
4、比较映射替换后的t和s是否一致，一致则返回true，不一致则返回false

### 代码

```c


bool isIsomorphic(char * s, char * t){
    if ((s == NULL) && (t == NULL)) {
        return true;
    } else if ((s == NULL) || (t == NULL)) {
        return false;
    }
    
    if (strlen(s) != strlen(t)) {
        return false;
    } 
    
    int i = 0;
    int hashS[256] = {0};
    int hashT[256] = {0};
    
    while (s[i] != '\0') {
        int indexS = s[i];
        int indexT = t[i];
        
        if ((hashS[indexS] == 0) && (hashT[indexT] == 0)) {
            hashT[indexT] = s[i];
            hashS[indexS]++;
        }

        t[i] = hashT[indexT];
        i++;
    }
    
    if (strcmp(s, t) == 0) {
        return true;
    } else {
        return false;
    }


}


```