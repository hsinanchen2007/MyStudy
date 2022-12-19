# 反转链表 II
### 题目
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。（1 ≤ m ≤ n ≤ 链表长度。）
```
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
```
### 思路
我们可以将链表分为三段去看：head->.... ->father->m->....>n->n+1 ->...
1. 对于从head开始到m-1位置，我们只需要移动pre和cur指针，直到找到m-1。注意，为了可以将反转完成的子段[m, n]连接回来，我们使用father指针将原始链表中m-1位置的结点保存起来。
2. 对于m到n位置，我们需要使用双指针进行链表反转。
- 下面介绍一下如何使用双指针链表反转：（与#206思路相同）
	- 定义两个指针： pre和 cur ；pre 在前 cur 在后。
	- 每次让 pre 的 next 指向 cur ，实现一次局部反转。
	- 局部反转完成之后， pre继续向前移动，cur更新为pre。
		- 这里我们可以发现，cur都是指向交换子段的头部位置，每次交换是将pre添加到cur链表的头部。     
		
    ```
    EG.
    设需要交换的子段：2(cur) -> 3(pre) -> 4(temp) -> 5 //使用temp保存下一个要更新的结点
    // 交换pre和cur所指结点 pre->next = cur
    3(pre) -> 2(cur)   4(temp) -> 5
    // 更新pre和cur指针 cur = pre; pre = temp
    3(cur) -> 2 4(pre) -> 5 //看到了吗！cur不是和pre连着的
    // 下一次交换 pre->next = cur
    4(pre) -> 3(cur) ->2  5(temp)
    更新pre和cur指针
    4(cur) -> 3 -> 2  5(pre) //所以每次cur都是指向子段第一个位置的！
    ```

    - 循环上述过程，直至 pre到达链表尾部

- 这里我们思考一个问题，为了将子段[m, n]连接回来，刚刚头部我们已经解决了，那么尾部该怎么连接呢？
	- 显然我们需要使得反转之后子串的最后一个结点指向son结点，那么反转后的最后一个结点是什么呢？我们目的是将m->....>n反转成n->....>m，显而易见最后一个结点就是原始链表中位置m的结点，所以我们同样使用last指针将它也保存起来！
	- 而原始链表中的n+1结点我们可以直接使用双指针的pre结点获取，这样就完美的把交换后的子串合进去了！

3. 对于n+1位置到最后，直接利用之前保存的last指针和最后一次反转更新的pre指针连接起来就好了！

### 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n || head == NULL) {
            return head;
        } 
        ListNode* pre = head;
        ListNode* cur = NULL;
        ListNode* father; //保存第m-1个结点
        ListNode* last; //保存交换后的第n个结点（其实就是交换前的第m个结点）
        int loc = 1; //记录pre的位置，从head(第二个位置)开始
        //loc代表下一次循环交换的位置，所有当loc等于n+1才能结束循环
        while(pre != NULL && loc <= n) {
            //从pre到达m，cur到达m-1开始处理
            if(loc < m) {
                //注意更新方式，cur要使用pre去更新，因为初始cur为NULL
                cur = pre;
                pre = pre->next;
                loc++;
            } else if(loc == m) { //保存父结点
                //注意如果m=1，则此时father是NULL
                father = cur; //保存第m-1个结点作为交换后的父结点
                last = pre; //保存第m个结点作为交换后的最后一个结点
                cur = pre;
                pre = pre->next;
                loc++;
            } else {
                ListNode* temp = pre->next; //保存pre的下一个结点
                //交换pre和cur结点:注意这里只需要将pre指向cur就好，因为cur每次都指向m位置（见下面解释），cur->next=temp会导致结点丢失！
                pre->next = cur;
                //更新pre和cur指针
                //因为是要整个反转（区分两两反转），所以cur其实每次指向的都是m位置上的结点，每次交换是将pre添加到cur链表的头部
                cur = pre;
                pre = temp;
                loc++;
            }
            if(loc == (n + 1)) {
                last->next = pre; //连接交换后的第n个结点和n+1个结点
                //不是从第一个结点开始交换的,father不为空，直接返回head即可
                if(father != NULL) {
                    father->next = cur;
                    return head;
                } else {
                    //否则当前cur指向的即为第一个结点
                    return cur;
                }
            }
        }
        //理论上都会进入上面的循环，因为在程序最初就限制了n不等于m
        return head;
    }
};
```


