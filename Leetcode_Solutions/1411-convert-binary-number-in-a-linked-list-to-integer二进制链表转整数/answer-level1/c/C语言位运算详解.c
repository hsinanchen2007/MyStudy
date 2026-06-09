分析：我是参考他人的代码才发现可以用位运算，惭愧。于是紧接着就修改了代码，看上去更加优雅且简洁了。那么我就说明下为什么这么做，算是给指出思想的来源。
我们都知道，任何形式的数据在计算机内部存储的形式都是二进制形式，而下面的代码巧妙的就是利用这一特点逐一读取并填充二进制位从而得到我们期望的数据。
```
int getDecimalValue(struct ListNode* head){
    int value = 0;
    struct ListNode * ptr = head;

    while (ptr)
    {
        value = (value << 1) | (ptr->val);
        ptr = ptr->next;
    }
    
    return value;
}
```
