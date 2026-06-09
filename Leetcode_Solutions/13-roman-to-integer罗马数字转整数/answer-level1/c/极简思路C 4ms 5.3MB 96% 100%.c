### 解题思路
依次判断即可。

### 代码

```c
int romanToInt(char * s){
    int count=0;
    while(*s){
        if(*s=='M') count+=1000;
        if(*s=='C'&&*(s+1)=='M') {
            count+=900;
            s++;
        }
        if(*s=='D') count+=500;
        if(*s=='C'&&*(s+1)=='D') {
            count+=400;
            s++;
        }
        if(*s=='C') count+=100;
        if(*s=='X'&&*(s+1)=='C') {
            count+=90;
            s++;
        }
        if(*s=='L') count+=50;
        if(*s=='X'&&*(s+1)=='L') {
            count+=40;
            s++;
        }
        if(*s=='X') count+=10;
        if(*s=='I'&&*(s+1)=='X') {
            count+=9;
            s++;
        }
        if(*s=='V') count+=5;
        if(*s=='I'&&*(s+1)=='V') {
            count+=4;
            s++;
        }
        if(*s=='I') count+=1;
        s++;
    }
    return count;
}
```