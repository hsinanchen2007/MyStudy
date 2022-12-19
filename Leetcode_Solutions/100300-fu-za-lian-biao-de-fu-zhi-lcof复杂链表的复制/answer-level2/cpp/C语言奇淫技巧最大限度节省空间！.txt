### 解题思路

![Snipaste_2020-03-30_12-00-30.png](https://pic.leetcode-cn.com/09e7cf0986c94824eef15101dc6a7bf2cfeac46cdca59d209368af70d508b6ec-Snipaste_2020-03-30_12-00-30.png)


这里内存消耗11.2MB，虽然已经打败了100%的用户，但是提交通过的方法还是借助了`map<Node*,Node*>`，将每个源节点和目标节点一一对应存储起来，以便实现目标链表的random指针指向正确，因为假如直接`destNode->random=srcNode->random`的话是错的，这样的结果是目标链表的`random`指向了源链表，因此，需要用`destNode->random=m.find(srcNode->random)->second`。然而还有更优化的方法，那就是可以不用`map<Mode*,Node*>`，因为`map`的作用就是将源节点和目标节点进行绑定，但是我们忽略了一个细节，就是`Node`节点是包含了一个`int`类型的变量`val`。我们知道在**现代**计算机上int类型的大小等于指针的大小，如32位机器上，`sizeof(int)==4==sizeof(任何指针)`,所以我们可以将源节点的`val`变量保存为目标节点的地址，只要注意类型转换就好了：`srcNode->val=*(int*)(void*)destNode`，如此就可以将源节点和目标节点进行绑定！而后续为目标节点赋值就可以`destNode->random=(Node*)(void*)&(srcNode->random->val)`。

![Snipaste_2020-03-30_12-49-59.png](https://pic.leetcode-cn.com/ebfbedba818c2da666d33e99c3d7519376ad70da5b597757c4241788507e2b5d-Snipaste_2020-03-30_12-49-59.png)


稍微遗憾的是不知道为什么在leetcode平台上无法通过，输出也很奇怪，如下图；

![Snipaste_2020-03-30_12-00-03.png](https://pic.leetcode-cn.com/f976a64dff3572496ca0e50349577c967bcb820ce3c2d9f66e3d8fcc9ccee7f4-Snipaste_2020-03-30_12-00-03.png)


虽然一时间不知道错误所在，但是巧妙借助C语言`void*`进行类型转换确实是C语言开发中的一个高级技巧，在这里分享给大家以供参考~

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node *newHead=new Node(head->val);
        Node *srcNode=head,*destNode=newHead;
        map<Node*,Node*> m;
        while(srcNode->next!=NULL){//先不考虑random的指向问题，先将链表复制下来解决好next指针问题
            destNode->next=new Node(srcNode->next->val);
            m.insert(pair<Node*,Node*>(srcNode,destNode));
            //srcNode->val=*(int*)(void*)destNode;//将srcNode的val保存为destNode的地址
            destNode=destNode->next;
            srcNode=srcNode->next;
        }
        m.insert(pair<Node*,Node*>(srcNode,destNode));
        //srcNode->val=*(int*)(void*)destNode;

        destNode=newHead;
        srcNode=head;
        while(srcNode!=NULL){
            if(srcNode->random==NULL)
                destNode->random=NULL;
            else{
                auto iter=m.find(srcNode->random);
                destNode->random=iter->second;
                //destNode->random=(Node*)(void*)&(srcNode->random->val);//将val变量转换为地址
            }
            destNode=destNode->next;
            srcNode=srcNode->next;
        }
        return newHead;
    }
};
```