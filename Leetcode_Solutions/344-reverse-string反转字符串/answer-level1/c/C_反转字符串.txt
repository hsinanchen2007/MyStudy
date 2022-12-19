### 解题思路
子串滚动的题需要这个函数

### 代码

```c
void reverseString(char* s, int sSize){

    int low=0,high=sSize-1;

    while(low<high)
    {
        char temp=s[low];
        s[low]=s[high];
        s[high]=temp;

        ++low;--high;
    }
}
```