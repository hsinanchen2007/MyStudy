### 解题思路
1. 记忆要点，`pPrev` 初始值是 `nullptr`，就是逆序之后结尾的 `nullptr`

2. `pCurr` 是 `head`

3. 判断以 `(pCurr != nullptr)` 为标准，因为如果 `pCurr` 为空，就不能 `->next` 了

4. 循环中需要 4 步操作，都是有前后关系的，就像交换两个数字一样，需要有个 `temp` 来保存

5. `pNext` = `pCurr->next` ，所以 `pCurr->next` 已经存起来了，它就可以改变了

6. `pCurr->next` = `pPrev` ，指向下一个改为指向上一个，同上 `pPrev` 就可以改变了

7. `pPrev` = `pCurr` ，后脚往前走一步

8. `pCurr` = `pNext` ，前脚往前迈一步

### 代码
```cpp
ListNode* reverseList(ListNode* head) 
{
    ListNode* pPrev = nullptr;
    ListNode* pCurr = head;
    while (pCurr != nullptr)
    {
        ListNode* pNext = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    return pPrev;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

