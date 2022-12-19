和女朋友开始复习算法最早印象深刻的写法，头尾双指针，from由前向后，to由后向前，使用O(1)的额外空间使字符串头尾两个元素调换，从而实现字符串反转。
```
void reverseString(char* s, int sSize){
    int from=0 ,to=sSize-1 ;
    char type;
    
    while(from<to)
    {
        type=s[from];
        s[from++]=s[to];
        s[to--]=type;
    }
    
    return s;

}
```
