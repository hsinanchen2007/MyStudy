每K个一组压栈，弹栈，记住head和前一组的end就可以了。

typedef struct ListNode Node;

int g_top = 0;

Node **g_stack = NULL;

#define PUSH(e) do { g_stack[g_top++] = (e); } while(0)
#define POP(e) do { (e) = g_stack[--g_top];  } while(0)

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int listLen = 0;
    int rsvertCnt;
    int rsvertOther;
    Node *pstNode = NULL;
    Node *headPushNode = NULL;
    Node *prePopNode = NULL;
    Node *subPreNode = NULL;
    int i;
    int j;
    
    if (head == NULL) {
        return NULL;
    }
    
    pstNode = head;
    while(pstNode) {
        listLen++;
        pstNode = pstNode->next;
    }
    
    if (k == 0 || listLen == 1 || k > listLen) {
        return head;
    }
    
    g_stack = (Node**)malloc(sizeof(Node*) * listLen);
    if (g_stack == NULL) {
        return head;
    }
    memset(g_stack, 0, sizeof(Node*) * listLen);
    
    rsvertCnt = listLen / k;
    rsvertOther = listLen % k;
    pstNode = head;
    headPushNode = head;
    
    for (i = 0; i < rsvertCnt; i++) {
        pstNode = headPushNode;
        for (j = 0; j < k; j++) {
            PUSH(pstNode);
            printf("push %d\n", pstNode->val);
            pstNode = pstNode->next;
        }
        headPushNode = pstNode;        
        
        for (j = 0; j < k; j++) {
            if (j == 0) {
                if (i == 0) {
                    POP(head);
                    //printf("head pop %d\n", head->val);
                    subPreNode = head;
                } else {
                    POP(pstNode);
                    //printf("pre node %d pop %d\n", subPreNode->val, pstNode->val);
                    prePopNode->next = pstNode;
                    subPreNode = pstNode;
                }
            } else {
                POP(pstNode);
                subPreNode->next = pstNode;
                subPreNode = pstNode;   
            }
        }
        prePopNode = pstNode;
        
    }

    prePopNode->next = headPushNode;
    
    //printf("list len %d times %d other %d\n", listLen, rsvertCnt, rsvertOther);
    return head;
}