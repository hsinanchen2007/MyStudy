```c++
class Solution {
public:
    //如果用非递归;迭代的形式去做 比如栈 我想的主要还是利用Node把父节点和是左是右存起来
    struct Node{
        int l,r;
        bool isleft;
        TreeNode* pa;
        Node(int L,int R, bool IsLeft,TreeNode *Pa):l(L), r(R), isleft(IsLeft),pa(Pa){}
    };

    
    // <1> 用递归去做 选择中点元素作为根节点,这个如果有偶数个的话,一定选择靠左的;
    // 一直选择靠右;随机选择靠左和靠右都可以;
    // 参考109,在数组中我们可以通过nums[mid]直接获得相应的数值,但是这是利用了数组的特殊性，
    // 而没有利用中序遍历序列的普遍性质;
    // 如果我们把递归的过程严格写成中序遍历的过程,在遍历完左子树之后,我们就要访问根节点,之后再遍历右子树,
    // 而我们访问根节点的顺序就是中序遍历序列的顺序, 所以我们可以设置一个index,指向接下来要遍历结点的数值
    // 这个index一开始指向中序遍历的开头,每访问一次后,这个index就向后移动一次

    // <2>迭代的方法 就是利用栈把迭代的方法给翻译过来
    // 为了解决不知道父节点是谁和是父节点的左子树还是右子树 所以设置Node结构记录相关的信息
    int index;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        index=0;     //<1> 递归的方法
        return recursion(nums,0,nums.size()-1);  //<1> 递归的方法

        // 迭代的方法
        TreeNode *h=new TreeNode(0); //哑的父节点 它的左子树是答案
        Node cur=Node(0,nums.size()-1,true,h);
        stack<Node> st;
        st.push(cur);
        while(!st.empty()){
            cur=st.top();
            st.pop();
            if(cur.l>cur.r) //空树
                continue;
            else{
                int mid=cur.l+(cur.r-cur.l)/2;
                TreeNode* r=new TreeNode(nums[mid]);
                if(cur.isleft) //是父节点的左子树
                    cur.pa->left=r;
                else  //右子树
                    cur.pa->right=r;
                if(mid-1>=cur.l) //构造左子树
                    st.push(Node(cur.l,mid-1,true,r));
                if(cur.r>=mid+1) //构造右子树
                    st.push(Node(mid+1,cur.r,false,r));
            }
        }
        return h->left;

    }

    TreeNode* recursion(vector<int>& nums,int l,int r){
        if(l>r)
            return NULL;
        else{
            int mid=(l+r)/2; //这个就是始终选择靠左   +1之后就是始终选择靠右 
            //为了防止溢出最好写成l+(r-l)/2 防止l+r溢出

            // TreeNode *root=new TreeNode(nums[mid]); // (1) 我们固然可以通过nums[mid]直接获得根节点的值
            TreeNode *root=new TreeNode(0); //(2)也可以充分利用中序遍历序列的性质，使用index
            if(mid-1>=l)
                root->left=recursion(nums,l,mid-1);
        
            root->val=nums[index];  //(2)  也可以充分利用中序遍历序列的性质，使用index
            ++index; //(2) 也可以充分利用中序遍历序列的性质，使用index

            if(r>=mid+1)
                root->right=recursion(nums,mid+1,r);
            return root;
        }
    }
};

```
