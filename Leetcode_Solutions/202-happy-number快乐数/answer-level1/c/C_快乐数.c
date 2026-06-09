### 解题思路
此题有个前提：所有的非快乐数寻找快乐的过程都是个循环。快乐数最后一定会找到1，而且1经过查找快乐的过程之后还是1。综上，无论什么数，寻找快乐的过程都是会循环的。
有了这个前提就可以用快慢指针，只要发现循环回来了，只需要判断是在1那里循环，还是在其他数字上循环，在1循环的一定是快乐数，否则不是。

### 代码

```c
void func(int* Nums)
{
    int sum=0;
    while(*Nums)
    {
        sum+=(*Nums%10)*(*Nums%10);
        *Nums=*Nums/10;
    }
    *Nums=sum;
}

bool isHappy(int n){
    int slow=n,fast=n;
    do
    {
        func(&slow);
        func(&fast);
        func(&fast);
    }
    while(fast!=slow);
    return slow==1;
}
```