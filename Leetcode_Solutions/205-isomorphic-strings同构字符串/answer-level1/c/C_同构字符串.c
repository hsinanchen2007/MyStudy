### 解题思路
大致意思就是“存在一个加密方法：把某一字符替换成另一字符，现在给你一个字符串s和一个字符串t，判断一下t是不是由s经过加密而得到的”.
通过“比较一个字符串中不同位置的不同字符，在另一字符串中相同位置是不是对应同样的字符”可以得出结论。
“判断每种字符在两个字符串中第一次出现的位置是否相同”这个方法挺巧妙的。
参考：https://leetcode-cn.com/problems/isomorphic-strings/solution/ji-lu-bing-bi-jiao-zi-mu-shou-ci-chu-xian-de-wei-z/

不太喜欢申请很多内存空间闲着，写了链表，牺牲时间换空间。
### 代码

```c
typedef struct Node{
    char data;
    int firstTime;
    struct Node* next;
}Node;
//建立链表
Node* newNode(char Data,int FirstTime)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->firstTime=FirstTime;
    n->next=0;
    return n;
}
//在字符串中第一次出现的位置
int firstTimeIn(Node* Link,char Data,int Local)
{
    //从链表中查找字符Data，返回Data第一次出现的位置
    Node* n=Link->next;
    while(n!=0)
        if(n->data==Data)
            return n->firstTime;
        else
            n=n->next;
    //如果没找到，就把Data和当前位置写入链表
    n=newNode(Data,Local);
    n->next=Link->next;
    Link->next=n;
    return Local;
}
//销毁链表
void delLink(Node* Link)
{
    while(Link!=0)
    {
        Node* n=Link;
        Link=Link->next;
        free(n);
    }
}

bool isIsomorphic(char * s, char * t){
    Node* linkForS=newNode('\0',-1);
    Node* linkForT=newNode('\0',-1);
    for(int i=0;s[i]!='\0'&&t[i]!='\0';++i)
        if(firstTimeIn(linkForS,s[i],i)!=firstTimeIn(linkForT,t[i],i))
        {
            delLink(linkForS);
            delLink(linkForT);
            return false;
        }
    return true;
}
```