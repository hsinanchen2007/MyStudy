struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
struct ListNode *temp = 0;
struct ListNode *newhead = 0;
struct ListNode *newheadFirstNode = 0;
struct ListNode *mNode = 0;
struct ListNode *mNodeBehind = 0;

if(m == n)
{
return head;
}

int i = 1;
newheadFirstNode = head;
while(i < m && newheadFirstNode)
{
if(i == (m - 1))
{
mNodeBehind = newheadFirstNode;
}
newheadFirstNode = newheadFirstNode->next;
i++;
}
mNode = newheadFirstNode;
while(i <= n && newheadFirstNode)
{
printf("%d\n", newheadFirstNode->val);
temp = newheadFirstNode->next;
newheadFirstNode->next = newhead;
newhead = newheadFirstNode;
newheadFirstNode = temp;
i++;
}
if(mNodeBehind)
{
mNodeBehind->next = newhead;
}else{
head = newhead;
}
mNode->next = newheadFirstNode;

return head;
}