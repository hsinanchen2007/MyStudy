思路如下：

每次顺序读取两个值，前一个比后面小的话，就说明出现了那六种情况，也就是需要用后一个值减去前一个值。比如：

s="IV";

此时，V-I即可的到值，反之，如果前一个值大于后一个值，那么，正常读取当前值即可

![romantoint.png](https://pic.leetcode-cn.com/a2d67e363770be56e206ebc410a8b3773ba80fbb565046dabcfa8cbb1661b8f4-romantoint.png)

```
int read(char a){
    switch (a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  printf("Input Error!\n");
                  return 0;
    }
}

int romantoint(char *s){
    int len = 0;
    int pos = 0;
    int sum = 0;
    int next = 0;
    for(len = 0;s[len]!='\0';len++);
    while(pos != len){
        printf("pos:%d\n",pos);
        if(s[pos+1] != '\0'){
            if(read(s[pos+1])>read(s[pos])){
                next = read(s[pos+1])-read(s[pos]);
                pos += 2;
                sum += next;
                continue;
            }
        }
        next = read(s[pos]);
        pos ++;
        sum += next;
    }
    return sum;
}
```

