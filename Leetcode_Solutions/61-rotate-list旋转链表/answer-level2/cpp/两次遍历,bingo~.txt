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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* tail = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            if (temp->next == NULL) {
                tail = temp;
            }

            length++;
            temp = temp->next;
        }
        temp = head;

        if (k >= length) {
            k = k % length;
        }

        if (k == 0) {
            return head;
        }

        while (length > k) {
            length--;
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        tail->next = head;
        head = temp;

        return head;
    }
};