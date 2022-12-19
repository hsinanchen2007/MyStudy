因为每个节点都有一个值，我们可以在这个上做文章。从头开始遍历，我们让第一个节点的值为0，到第二节点的值时为1，依次这样下去。
在遍历的过程中，我们不断判断即将遍历的节点的值是多少，如果其值小于等于前一个节点的值且大于0（我们赋予的第一个节点的值），那么这个值很有可能是回环的节点，我们找到前面也是这个值的指针，然后比较两者是否相等。
若相等，则说明回环。
若不相等，继续按之前的方式继续遍历，继续累增赋值，最后找到回环的点，或者找到NULL(说明不存在回环)
来自博客：https://blog.csdn.net/m0_37697335/article/details/105152522

感觉执行效率跟快慢指针差不多。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    int i = 0;
    struct ListNode *q = head;
    if(NULL == q)
        return false;
    while(1)
    {
        q->val = i; 
        q = q->next;
        if(NULL == q)
            return false;
        if((q->val <= i) && (q->val >= 0))
        {
            struct ListNode *p = head;
            for(int j=0; j<(q->val); j++)
            {
                p = p->next;
            }

            if(p == q)
                return true;
        }
        i++;
    }
}
```
