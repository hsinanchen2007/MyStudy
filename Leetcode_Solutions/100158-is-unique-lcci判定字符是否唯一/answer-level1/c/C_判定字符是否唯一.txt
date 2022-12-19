### 解题思路
方法1 暴力法，一个一个对比（题目加分）
方法2 哈希表，建立哈希表，一边遍历字母，一边记录每个字母出现的次数，次数大于1直接返回false（用了散列，题目不加分）
方法3 先快速排序，然后相邻的两个字符进行异或操作，相同的时候异或操作的结果是0，直接返回false即可（避免使用其他数据结构 + 比暴力更快速）

提示： 传入空字符串或者空指针返回0即可

方法三 可以双百
![image.png](https://pic.leetcode-cn.com/42428ebf8018a7bc713f50f347d5262e9c6dfa93153a8946b2e11757cdef989f-image.png)

### 代码

```c
//----------------------------------------------------------------方法一 暴力
bool isUnique(char* astr){
    if(astr==0||astr=="")return 0;
    
    for(int i=0;astr[i]!='\0';++i)
        for(int j=0;astr[j]!='\0';++j)
            if(i!=j&&astr[i]==astr[j])
                return 0;
    return true;
}

//----------------------------------------------------------------方法三 快速排序 + 异或
void sort(char* Str,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High;char temp=Str[Low];
        while(i!=j)
        {
            while(i<j&&temp<Str[j])--j;
            if(i<j)Str[i++]=Str[j];
            while(i<j&&temp>Str[i])++i;
            if(i<j)Str[j--]=Str[i];
        }
        Str[i]=temp;
        sort(Str,Low,i-1);
        sort(Str,i+1,High);
    }
}
bool isUnique(char* astr){
    if(astr==0||astr=="")return 0;
    int length=0;
    for(int i=0;astr[i]!='\0';++i)
        ++length;
    sort(astr,0,length-1);
    for(int i=0;i+1<length;++i)
        if((astr[i]^astr[i+1])==0)
            return false;
    return true;
}
```