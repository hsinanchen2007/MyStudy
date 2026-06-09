### 解题思路
我的思路很简单，先复制主链，之后再复制random指针。
当然后面的复制random指针使用遍历，觉得应该有更好的算法

### 代码

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        
        Node*i=head,*j,*head2=j=new Node{head->val};
        
        while(i->next){
            i=i->next;
            j->next=new Node(i->val);
            j=j->next;
        }//copy the main list
        
        i=head;
        j=head2;
        Node*tmp1,*tmp2;
        while(i){
            if(i->random==NULL){
                (*j).random = NULL;
                i = i->next;
                j = j->next;
                continue;
            }
            
            tmp1=head;
            tmp2=head2;
            while(tmp1!=i->random){
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
            (*j).random=tmp2;
            i=i->next;
            j=j->next;
        }//copy the rondom pointer
        return head2;
    }
};
```
主要炫耀一下第一次均排在前列的时间和内存消耗。![2020-02-05 20-37-08 的屏幕截图.png](https://pic.leetcode-cn.com/466acd576cb3e537fe2286ff553587ca374b6841af9750c1da1823047752faac-2020-02-05%2020-37-08%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)
