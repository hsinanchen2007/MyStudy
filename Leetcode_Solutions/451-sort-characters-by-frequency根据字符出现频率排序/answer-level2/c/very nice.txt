### 解题思路
hash table
![image.png](https://pic.leetcode-cn.com/002c2fb71e63feb23ec579a8cf3d458ba01f61840bb687a2c424d1966831e14b-image.png)


### 代码

```c
char * frequencySort(char * s){
    int h[130]={0},i,max=0,flag=0;
    char *p=s,t;
    while(*p!=0){
        h[*p]++;
        p++;
    }
    p=s;
    while(1){
        flag=0,max=0;
        for(i=0;i<130;i++){
            if(h[i]>max){
                max=h[i];
                t=i;
                flag=1;
            }
        }
        if(!flag) break;
        while(h[t]--){
            *p++=t;
        }
    }
    return s;
}
```