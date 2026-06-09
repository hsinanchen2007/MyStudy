这道题，解法很多，比如采用建立完全二叉堆的佛洛依德算法，时间复杂度也是 `O(N)`

给出一个单调栈解法。


以测试案例为例，一个输入序列：`[3, 2, 1, 6, 0, 5]`。 设置一个辅助栈，从大到小存储。
过程如下：
+ 首先入栈3
+ 2 比 3 小，入栈
+ 1 比 2 小，入栈
+ 6 大于1，因此要弹出1，1在2和6之间选择二者之间较小的元素作为父节点，因此选择2。1在2的右侧，使得1作为2的右子节点
+ 弹出1后，6仍然比2大，同理2要在3和6之间选择一个作为父节点。3比6小，因此选择3。2在3的右侧，因此2作为3的右子节点
+ 同理弹出3，让3作为6的左子节点
+ 入栈6
+ 入栈0
+ 入栈5的时候比0大，要弹出0，选择5作为父节点，并且0是5的左孩子
+ 弹出5，左侧是6，作为5的父节点
+ 6最后弹出，就是根节点


结合算法
```cpp

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        if(nums.empty()) 
            return nullptr;
            
        std::stack<TreeNode*> nodes;
        
        TreeNode* curNode = nullptr;

        for(size_t i=0; i < nums.size(); ++i) { 

            while(!nodes.empty() && nodes.top()->val  <  nums[i]) { 
                TreeNode* top = nodes.top(); 
                nodes.pop();

                if(!nodes.empty() && nodes.top()->val < nums[i]) {
                    nodes.top()->right = top;
                }
                else  {
                    curNode = new TreeNode(nums[i]);
                    curNode->left = top; 
                }
            }

            // push 
            if(curNode){
                nodes.push(curNode);
                curNode = nullptr;
            }
            else {
                nodes.push(new TreeNode(nums[i]));
            }
            
        }

        // 遍历结束，此时栈中可能还是会有一个元素
        while(!nodes.empty()) { 
            curNode = nodes.top(); nodes.pop();

            if(!nodes.empty()) 
                nodes.top()->right = curNode;
            
        }

        return curNode;
    }
};
```