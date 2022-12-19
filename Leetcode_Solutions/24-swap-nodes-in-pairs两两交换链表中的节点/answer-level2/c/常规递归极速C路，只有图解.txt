效率(不排除有误差):
![image.png](https://pic.leetcode-cn.com/4767e0207246332d24625c9e955023d1860a6eabff4d79bffa60158fe5c4d093-image.png)
```
typedef struct ListNode* PtrToNode;

struct ListNode* swapPairs(struct ListNode* head){
    PtrToNode B = NULL;                             
    if(head == NULL)
        return NULL;
    if(head->next != NULL){                
        B = head->next;   
        if (B->next == NULL){                                                                           
            B->next = head;
            head->next = NULL;           
        }else
        {            
            head->next = B->next;
            B->next = head; 
            head->next = swapPairs(head->next);                                       
        }
    }else
        return head;
    return B;
}
```
![微信图片_20191218233714.jpg](https://pic.leetcode-cn.com/b7449a6d6db516d2280124fcbc281235e7923431bcf3103fc2137c9e3863e5f3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191218233714.jpg)

