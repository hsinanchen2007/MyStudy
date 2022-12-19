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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( l1 == NULL )return l2;
        if( l2 == NULL )return l1;
        ListNode* dummy = new ListNode( -1 );//定义一个哑节点，为后续的头插法做准备
        std::stack<int> stk_1, stk_2;          //定义两个栈，将链表值先push进去再逐个pop出来进行计算
        int input = 0;                         //进位值初始化
        int val_1, val_2;                      //两个记录stk_1和stk_2 pop出来的值的变量
        //链表值入栈
        while( l1 != NULL )
        {
            stk_1.push( l1->val );
            l1 = l1->next;
        }
        while( l2 != NULL )
        {
            stk_2.push( l2->val );
            l2 = l2->next; 
        }
        //链表值出栈计算,结果保存到新链表
        while( !stk_1.empty() || !stk_2.empty() ) //只要有一个没有遍历完，就继续
        {
            if( !stk_1.empty() )
            {
                val_1 = stk_1.top();
                stk_1.pop();
            }else{
                val_1 = 0;          //为空了就赋值为0，(注意要停止pop!)不影响加法计算
            }
            if( !stk_2.empty() )
            {
                val_2 = stk_2.top();
                stk_2.pop();
            }else{
                val_2 = 0;          //为空了就赋值为0，(注意要停止pop!)不影响加法计算
            }
            int add_res = val_1 + val_2 + input;
            input = add_res / 10;              //更新进位值 input
            //头插法保存结果
            ListNode* res_node = new ListNode( add_res % 10 );
            res_node->next = dummy->next;
            dummy->next = res_node;
        }
        if( input != 0 )//如果最后一个结果还要进位，就还需要再新建一个节点保存进位值并插入
        {
            ListNode* input_node = new ListNode( input );
            input_node->next = dummy->next;
            dummy->next = input_node;
        }
        return dummy->next;
    }
};