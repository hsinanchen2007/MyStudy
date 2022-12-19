### 解题思路
![Snipaste_2020-03-19_16-06-12.png](https://pic.leetcode-cn.com/26ad9c0000f7918a2503687c1b24e58404b6faf90647b54452e8e8480252e1a3-Snipaste_2020-03-19_16-06-12.png)
各字母计数，常规思路

### 代码

```c
int maxNumberOfBalloons(char * text){
    int anum=0,bnum=0,lnum=0,onum=0,nnum=0;
    int len=strlen(text);
    if(len<7) return 0;
    int i;
    for(i=0;i<len;i++){
        switch(text[i]){
            case 'b': bnum++;break;
            case 'a': anum++;break;
            case 'l': lnum++;break;
            case 'o': onum++;break;
            case 'n': nnum++;break;
            default: break;
        }
    }
    onum=onum/2;
    lnum=lnum/2;
    int sum=0;
    while(anum>0&&bnum>0&&onum>0&&lnum>0&&nnum>0){
        sum++;
        anum--;
        bnum--;
        onum--;
        lnum--;
        nnum--;
    }
    return sum;
}
```