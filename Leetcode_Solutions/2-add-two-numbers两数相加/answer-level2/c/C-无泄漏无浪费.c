# 0空间分配
* 思路:
*   使用L1+L2的节点空间进行值的存储
*   先使用L1存储，如果L2.len > L1.len, 当前的Node->next = 当前L2.Node ;
*   如果最高位进位了,导致当前Node->next == NULL,继续使用L2的头节点
*   潜在风险：造成l2某段内存泄漏 或者 DoubleFree, LeetCode居然可以通过
*   20ms/8.3MB
  
# 具体实现如下
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //进位标志、当前和
    int flag = 0,nodeSum = 0;
    //L1头、当前指针、L2头
    struct ListNode *ret,*now,*high;
    
    // L1有 || L2有 || 进位  
    for(ret = l1, now = l1, high = l2 ;l1  || l2  || flag ;) {  
        //如果后半部分使用L2空间不足 继续使用L2头节点的空间
        if (l1 == NULL && l2 == NULL) {
              now->next = high;
              now = now->next;
        }
        
        //做加法
        nodeSum = ( l1  ? l1->val : 0 ) + (l2 ? l2->val : 0) + flag;  
        now->val = nodeSum % 10;    
        flag =  nodeSum / 10; 

        //l1、l2指针后移
        l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
        l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;
        
        //如果l1存在，继续沿用L1的空间 如果L1结束了，沿用l2的空间
        now->next = ( l1 ? l1 : (l2 ?  l2 : NULL) );
        //now后移
        now->next ? now = now->next : NULL;
    }
    return ret;
}
```
# 无内存泄漏版本
*   思路：
*   在L1空间消耗完毕时,记录当前L2位置,返回前修改L2指针位置
*   20ms/8.3MB

具体实现如下：
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int flag = 0, nodeSum = 0, freeflag = 0;
    struct ListNode *ret,*now,*high,*freeBegin,*freeEnd;
    for(ret = l1, now = l1, high = l2, freeBegin = l2;l1  || l2  || flag ;) {  
        if (l1 == NULL && l2 == NULL) {
              now->next = high;
              now = now->next;
              freeBegin = now->next;
        }
        nodeSum = ( l1  ? l1->val : 0 ) + (l2 ? l2->val : 0) + flag;  
        now->val = nodeSum % 10;    
        flag =  nodeSum / 10; 
        l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
        if(l1 == NULL && 0 == freeflag && l2) {
            freeEnd = l2;
            freeflag = 1;
        }
        l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;
        now->next = ( l1 ? l1 : (l2 ?  l2 : NULL) );
        now->next ? now = now->next : NULL;
    }
    l2 = freeBegin;
    freeEnd->next = NULL;
    return ret;
}
```