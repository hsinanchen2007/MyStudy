### 解题思路
解答问题的关键在于比较s[i]与s[i + 1]
如果s[i]的值小于s[i + 1]，则减去s[i]
否则加s[i];

这里求s[i]的值没有采用查表的方法，这样太慢，可以通过hash表来实现；
这里采用简单判断即可，如果需要遍历时再采用hash表来实现

### 代码

```c
int getValue(char e)
{
    switch(e){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: break;
    }
    return 0;
}

int romanToInt(char * s){
    int n = strlen(s);
    int num = 0;
    for(int i = 0; i < n; i++){
        int next = i + 1;
        if(next < n && getValue(s[next]) > getValue(s[i])){
            num -= getValue(s[i]);
        } else{
            num += getValue(s[i]);
        }
    }
    return num;
}


```