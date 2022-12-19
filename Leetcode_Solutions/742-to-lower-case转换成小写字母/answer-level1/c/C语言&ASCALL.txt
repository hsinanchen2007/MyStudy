# small tip:
91-96为非字母字符，注意排除，不然以下用例通不过
![11111.png](https://pic.leetcode-cn.com/e1e0bf2f5dacb1b0fadefd23df999f3427676227430b9a058ce0e57cb7502a79-11111.png)
```
char * toLowerCase(char * str){
    int length=strlen(str),i;
    for(i=0;i<length;i++){
        if((str[i]-'a')<0&&(str[i]-'A')>=0&&(str[i]-'A')<=25)
            str[i]+=32;
    }
    return str;
}
```
