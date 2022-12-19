```
int myAtoi(char * str){
    long long int num = 0;

    sscanf(str, "%lld", &num);
    if (num > 2147483647) return 2147483647;
    if (num < -2147483648) return -2147483648;
    return (int)num;
}
```

scanf 除了可以从文件中读取，还可以从字符串中读取

sscanf(从哪读，读什么，读到哪)