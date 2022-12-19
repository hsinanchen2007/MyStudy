### 解题思路
类似快速排序

### 代码

```c
bool isAEIOU(char C)
{
    return C=='A'||C=='E'||C=='I'||C=='O'||C=='U'||
            C=='a'||C=='e'||C=='i'||C=='o'||C=='u';
}
int strLength(char* Str)
{
    int length=0;
    while(*Str!='\0')
    {
        ++Str;
        ++length;
    }
    return length;
}
char * reverseVowels(char * s){
    int low=0,high=strLength(s);
    while(low<high)
    {
        while(low<high&&!isAEIOU(s[high]))--high;
        while(low<high&&!isAEIOU(s[low]))++low;

        char temp=s[low];
        s[low]=s[high];
        s[high]=temp;
        ++low;--high;
    }
    return s;
}
```