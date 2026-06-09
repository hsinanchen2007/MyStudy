### 解题思路
因为形参类型中已经给定了指向两个数组首地址的指针，只需要在函数体中进行指针的移动和解引用即可，其中较难点就是要注意解引用*与++的优先级，还有一个就是要实现声明一个常量count并初始化为0，该常量的作用就是来标记猜对的数目，最后返回该值；因为题目已经限制了猜数字的数目，实际上guessSize和answerSize我认为作用不大；

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize)
{
    int count = 0;
    for(int i=0;i<3;i++)
    {
        if(*guess++ == *answer++)  //因为++优先级要高于*，其实相当于*(guess++)和*(answer++)先自增后解引用；
        count++;
    }
    return count;
}
```