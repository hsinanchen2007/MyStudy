### 解题思路
太无脑了
![33.jpg](https://pic.leetcode-cn.com/616b3a58d51757c8be78e05c99bf827a8df3fa61e49d989b71c44eabcad3e8c6-33.jpg)

### 代码

```c
char * generateTheString(int n){
    if(!n) return NULL;
    char * string=(char *)malloc(sizeof(char)*500);
    char * temp=string;
    if(n%2==1){
        while(n>0){
            *string='a';
            n--;
            string++;
        }
    }else{
        int round=n-1;
        while(round>0){
            *string='a';
            round--;
            string++;
        }
        *string='b';
        string++;
    }
    *string='\0';
    return temp;
}
```