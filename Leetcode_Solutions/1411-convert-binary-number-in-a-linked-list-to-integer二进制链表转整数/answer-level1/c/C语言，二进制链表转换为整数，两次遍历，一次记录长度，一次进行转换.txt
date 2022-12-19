如标题，代码如下：
```
int getDecimalValue(struct ListNode* head){
    int num = 0;//记录转化之后的十进制数
    int flag = 0;//记录链表结点个数
    struct ListNode* p = head;
    while(p->next){//若当前结点不是尾结点
        flag++;//链表元素个数加1
        p = p->next;//指针后移一个结点
    }//循环执行结束之后得到链表中结点的个数

    //接下来开始进行转化，从最高位开始依次到最低位
    p = head;
    while(p->next){
        if(p->val==1){
            num = num + pow(2,flag);   
        }//结点val为0时，乘以权值仍旧为0，因此可不计算
        flag--;
        p=p->next;
    }//循环中没有对链表尾结点的值进行计算，因此最后需要注意到
    num = num + p->val;
    return num;
}
```
疑惑：本题中为什么头结点head也存储了数据呢？