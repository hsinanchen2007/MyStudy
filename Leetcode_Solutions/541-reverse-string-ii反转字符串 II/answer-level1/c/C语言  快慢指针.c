### 解题思路
隔2k翻转一次k个数的区间，剩下的小于k个数的，全部反转即可

### 代码

```c
void serverse(char *a,int begin,int end)
{
    while(begin<=end)
    {
        char tmp=a[begin];
        a[begin]=a[end];
        a[end]=tmp;
        begin++;
        end--;
    }
}
char * reverseStr(char * s, int k){  
    int i=0;
    for(i=0;i<strlen(s);i+=2*k)
    {
        if(strlen(s)-i>=k)
            serverse(s,i,i+k-1);    
        else
            serverse(s,i,strlen(s)-1);  //尾部少于k的部分
    }
    return s;

}
```