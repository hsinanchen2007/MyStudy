### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了67.65%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了100.00%的用户
首先需要知道，将6翻转成9，相当于6所在的那一位加上3，如：6999 翻转后 9999 相当于6999 + 3000
这样我们只需知道第一个6出现的位置，就可以加上对应的数字并返回
### 代码

```c
int maximum69Number (int num){
    char* s;
    int len;
    int i;
    s = (char*)malloc(sizeof(char)*5);
    sprintf(s,"%d",num);
    len = strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i] == '6')
        {
            num = num + (int)(pow(10,len-i-1)) * 3;
            free(s);
            return num;
        }
    }
    free(s);
    return num;
}
```