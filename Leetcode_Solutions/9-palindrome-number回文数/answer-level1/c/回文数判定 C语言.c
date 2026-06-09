### 解题思路
1.计算数字位数
2.反转并保存为字符串(字符数组)
3.双指针对比

### 代码

```c
// 保存为字符串
void InToStr(int x,char *str){
    int i = 0;
    while(x){
        *(str+i) = (char)(x%10);
        x/=10;
        i++;
    }
}
// 长度
int length(int x){
    int len = 0;
    while(x){
        x/=10;len++;
    }
    return len;
}
bool isPalindrome(int x){
    if(x<0) return false;
    int len = length(x); //测长用于申请空间
    char *s =(char*)malloc(len*sizeof(char)); // 分配空间
    InToStr(x,s);
    int l = len ;
    while(l){
        if(*(s+l-1)!=*(s+len-l))return false; //出现差异则返回false
        l--;
    }
    return true;
}
```