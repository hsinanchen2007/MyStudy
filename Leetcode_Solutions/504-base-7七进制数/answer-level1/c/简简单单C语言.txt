### 解题思路
![image.png](https://pic.leetcode-cn.com/82f0c056fed9693dbe5fa1d3b5d231a2d8210e652ba157e1e378625037b1161b-image.png)


### 代码

```c
char * convertToBase7(int num){
    int flag = num > 0 ? 1 : -1;
    num = abs(num);
    int i = 0, j;
    char temp;
    char* ret = (char*)malloc(10000);
    if(num == 0) {
        sprintf(ret, "%d", 0);
        return ret;
    }
    int* res = (int*)malloc(sizeof(int) * 10000);
    while(num > 0) {
        res[i++] = num % 7;
        num /= 7;
    }
    int* res1 = (int*)malloc(sizeof(int) * i);
    for(j = 0; j < i; j++) {
        res1[j] = res[j];
    }
    num = 0;
    for(j = i - 1; j >= 0; j--) {
        num *= 10;
        num += res1[j];
    }
    free(res);
    free(res1);
    sprintf(ret, "%d", flag * num);
    return ret;
}
```