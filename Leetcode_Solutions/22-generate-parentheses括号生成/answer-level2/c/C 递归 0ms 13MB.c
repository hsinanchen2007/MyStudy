# 主要思路是当前位置可以填什么？
记录还有多少个左括号（n），记录当前能填多少个右括号（k）
如果只有左括号没有右括号，则填左括号，递归（下一个位置左括号数减一，有括号数加一）
如果左右括号都能填，则先填左括号，递归，然后填右括号，再次递归（注意是在相同的位置填两次并分别递归）
如果只有右括号没有左括号，则填右括号，递归（下一个位置左括号数不变，有括号数减一）
如果左右括号都填完了，则输出结果

# 结果总数量
有n组括号时，不考虑是否有效，相当于把n个左括号塞进2n个位置里，有C(2n,n)个结果
当考虑是否有效时，参考卡特兰数 num = C(2n,n)/n

# 代码

```
void add_item(char** result, int* returnSize, char* str, int addr, int n, int k){
    if(n && !k){
        str[addr] = '(';
        add_item(result, returnSize, str, addr + 1, n - 1, k + 1);
    }else if(n && k){
        str[addr] = '(';
        add_item(result, returnSize, str, addr + 1, n - 1, k + 1);
        str[addr] = ')';
        add_item(result, returnSize, str, addr + 1, n, k - 1);
    }else if(!n && k){
        str[addr] = ')';
        add_item(result, returnSize, str, addr + 1, n, k - 1);
    }else if(!n && !k){
        //printf("%d %s\n", *returnSize, str);
        str[addr] = '\0';
        char* tmp = malloc(sizeof(char) * (addr + 1));
        memcpy(tmp, str, addr + 1);
        result[*returnSize] = tmp;
        *returnSize += 1;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    //num = C(2n,n)/n
    int num = 1;
    for(int i = 1; i < n; i++){
        num *= (2 * n - i + 1);
        num /= i;
    }
    num /= n;
    num = num ? num : 1;
    //printf("%d\n",num);
    
    char** result = malloc(sizeof(char*) * (num));
    *returnSize = 0;
    char* str = malloc(sizeof(char) * (n * 2 + 1));
    memset(str, 0, (n*2+1));
    add_item(result, returnSize, str, 0, n, 0);
    //printf("%d\n",*returnSize);
    return result;
}
```
