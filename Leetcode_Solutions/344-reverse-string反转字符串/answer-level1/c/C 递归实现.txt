### 代码

```c
//定义函数swap(left, right)
//如果left>=right则什么也不做
//否则，交换left和right，并调用swap(left+1, right-1)

void swap(char *left, char *right)//##用指针而不用引用，因为需要比较位置
{
    if(left>=right) return;
    else
    {
        //交换
        char temp = *left;
        *left = *right;
        *right = temp;
        //递归
        swap(left+1, right-1);
    }
}

void reverseString(char* s, int sSize){
    //异常：字符串为空
    if(sSize==0) return;

    swap(s, s+sSize-1);
}
```