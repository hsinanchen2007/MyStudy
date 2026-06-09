### 解题思路
见注释

### 代码

```c
int titleToNumber(char * s){
    int len =1; // 字符长度
    long int sum =0; // 结果
    int i =1; // 临时变量
    // 计算长度
    while (s[len]!='\0')
    {
        len++;
    }
    // 计算结果
    while(i<=len){
        int temp = s[len-i]-'A'+1;
        sum += temp*pow(26,i-1);
        i++;
    }
    return sum;
}
```