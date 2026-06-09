### 解题思路
利用 % 和 / 把数从低位到高位入栈，再逐个出栈和低位比较。
0要单独考虑
负数直接返回false

### 代码

```c
typedef struct Node{
    int data;
    struct Node* next;
}node;

node* newNode(int Data)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=Data;
    n->next=0;
    return n;
}

bool isPalindrome(int x){

    if(x==0)return true;
    if(x<0)return false;

    node* head=newNode(0);

    int num=x;
    while(num!=0)
    {
        node* n=newNode(num%10);
        n->next=head->next;
        head->next=n;
        num/=10;
    }

    int flag=1;
    while(head->next!=0)
        if(x%10==head->next->data)
        {
            x/=10;
            node* del=head->next;
            head->next=del->next;
            free(del);
        }
        else
        {
            flag=0;
            break;
        }
    free(head);

    return flag;
}
```