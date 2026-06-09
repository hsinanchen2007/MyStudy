```c++
class Solution {
public:
    ListNode* cur; //cur记录的值是为这棵子树的根节点的值
    int len;

    
    void calLen(ListNode* head){
        len=0;
        while(head!=NULL)
            ++len,head=head->next;
    }
    // <1>
    // 这个不需要设置快慢指针，不需要转成数组的方法非常巧妙；它模拟我们进行中序遍历的过程，
    // 首先设置计算链表的长度，接下来设置l和r变量，表示这棵子树的范围，当l>r的时候，递归终止，不需要再往下进行；
    // 当我们遍历完左子树后，就可以访问根节点，而我们通过全局变量，指向链表的指针cur，可以知道对应的val是多少，
    // 访问完之后，我们重新设置cur，因为链表的顺序就是中序遍历的顺序，所以cur=cur->next，接下来再遍历右子树，
    // 再把根节点和左右子树接起来即可。非常巧妙，充分利用了中序遍历的性质。

    //<2>设置快慢指针,同时设置左开右闭的l和r 对于链表来说找中点，除了遍历知道长度后，再移动的方法，也可以使用快慢指针，
    // 从l开始移动，快指针一次移动两步，慢指针一次移动一步，当快指针移动到r或者后面一步就是r时，慢指针指向的位置就是根节点的位置
    // 而由于是左开右闭的l和r，对于左子树来说新的l和r就是l和slow; 对于右子树来说新的l和r就是slow->next和r。
    TreeNode* sortedListToBST(ListNode* head) {
        // calLen(head); //<1> 首先计算长度 
        // cur=head; //<1> 我们要访问的第0个元素 就是head对应的元素 所以设置cur为head
        // TreeNode* root=recursion(0,len-1);  // <1>

        TreeNode* root=recursion_fastslow(head,NULL); //<2> 范围是左闭右开 所以是head和NULL
        return root; 
    }

    TreeNode* recursion(int l,int r){
        if(l>r) //空树 
            return NULL;
        else{
            int mid=l+(r-l)/2; //和108一样 我们选择中间靠左或者中间靠右的作为根节点都是可以的
            TreeNode *lt=recursion(l,mid-1); //遍历左子树，访问子树的根节点
            TreeNode *root=new TreeNode(cur->val); //cur->val对应的就是根节点的值,因为我们是按照中序遍历的顺序进行访问的
            cur=cur->next; //更新cur,因为链表记录的是中序遍历的顺序,所以cur=cur->next即可
            TreeNode *rt=recursion(mid+1,r); //遍历右子树
            root->left=lt; //设置好左右子树和根节点
            root->right=rt;
            return root;
        }
    }

    TreeNode* recursion_fastslow(ListNode* l, ListNode* r){ 
        if(l==r) //范围是左闭右开 这就说明为空了 
            return NULL;
        else{
            ListNode *fast=l, *slow=l; //快慢指针都是从l开始
            while(fast != r && fast->next != r){ //这是fast能够移动两步的条件即距离r有至少两步的距离
                // fast要么不移动 要么一定移动两步
                fast=fast->next->next; //fast移动两步
                slow=slow->next; //slow移动移动
            }
            TreeNode* root=new TreeNode(slow->val); //slow所在的位置就是链表中的位置，根节点的位置
            root->left=recursion_fastslow(l,slow); //左子树的范围就是[l,slow)
            root->right=recursion_fastslow(slow->next,r); //右子树的范围就是[slow->next,r)
            return root;
        }
    }
};
```

