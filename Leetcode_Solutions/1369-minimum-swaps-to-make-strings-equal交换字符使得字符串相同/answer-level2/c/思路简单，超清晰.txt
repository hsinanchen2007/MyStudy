### 解题思路
转化为数学问题，很简单。
![image.png](https://pic.leetcode-cn.com/51ecb8fcf82abcc19177d4af5b358aa960b3be1989f98505dbe231c861557620-image.png)

### 代码

```c
int minimumSwap(char * s1, char * s2){
    int n1=0,n2=0;
    char *p1,*p2;
    p1=s1,p2=s2;
    while(*p1!='\0'){
        if(*p1=='x'&&*p2=='y') n1++;
        else if(*p1=='y'&&*p2=='x') n2++;
        p1++,p2++;
    }
    if((n1+n2)%2==1) return -1;
    else{
        if(n1%2==0){
            return n1/2+n2/2;
        }
        else return n1/2+n2/2+2;
    }
}
```