我哭了，这题的测试是不是有什么问题啊。
如果在取随机数rand()%k之前加一句srand((int)time(0));的话，就没办法通过了，说我答案错误。。。
难道不是加了srand((int)time(0));的话，随机性就更强了么，，，（不过这样的话，确实就应该没有答案了，因为随机出来的东西应该是不会有标准答案的。。）
（难道题目的意思是说明白要加就行，这道题里就不要加了的意思么，，）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <ctime>
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int k,ran;
        ListNode *now_choosenode,*p;
        now_choosenode = head;
        p = head->next;
        k = 2;
        //srand((int) time(0));
        while(p)
        {
            ran = rand()%k;
            if(ran == 0)
            {
                now_choosenode = p;
            }
            k++;
            p = p->next;
        }
        return now_choosenode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */