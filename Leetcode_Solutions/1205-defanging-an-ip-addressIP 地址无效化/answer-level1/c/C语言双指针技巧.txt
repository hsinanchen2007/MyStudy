### 解题思路
j为慢指针，i为快指针。

### 代码

```c
char * defangIPaddr(char * address){

    int len = strlen(address);
    char* result = (char*)malloc(sizeof(char) * (len + 7));     //位数是固定的
    int j = 0;

    for ( int i=0; i<len; i++ ){        //i指针遍历address
        if ( address[i] == '.' ){
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        }
        else{
            result[j++] = address[i];
        }
    }
    result[j] = '\0';

    return result;
}
```