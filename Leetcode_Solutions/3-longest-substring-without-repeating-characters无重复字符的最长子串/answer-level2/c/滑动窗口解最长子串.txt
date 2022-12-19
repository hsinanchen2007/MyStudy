### 解题思路
利用滑动窗口，p是窗口起点，q是窗口终点，
if *q!=窗口中的元素，则将*q加入到窗口中，
q不断向前移动。
if *q==窗口元素，则将窗口缩短。

### 代码

```c
int lengthOfLongestSubstring(char * s){
    char *p;
    char *q;
    int max_length = 0;
    int length =0;
    p=s;
    q=p;
    char *t;
    t=p;
    if(!*p) return 0;
    while(*(++q)){
        for(t=p;t<q;t++){
            if(*t==*q){
                p=t+1;
                break;
            }
        }
        length = q-p;
        max_length=length>max_length?length:max_length;
       /* for(t=p;t<q;t++){
            printf("%c",*t);
        }
        printf("\n");*/
    }
    return (max_length+1);
}
```