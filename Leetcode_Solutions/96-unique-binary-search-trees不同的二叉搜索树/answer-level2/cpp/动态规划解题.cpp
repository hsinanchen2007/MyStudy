### 解题思路
本题是求二叉树的种数，二叉树是每个节点值唯一，且**左子树中全部小于根节点值，右子树中全部大于根节点值**
用result[i]表示i个节点可能形成多少种树
1. 现在有n个节点，就有**n种可能的根节点，即n大类**
2. 其中每个大类中又分为**两大类：1、左子树种类 2、右子树种类**
    求左子树种类又相当于求i-1个节点可以形成多少种
    求左子树种类又相当于求n-i个节点可以形成多少种树
    得出左右子树的种树，两者相乘即是以i为根节点的种
3. result[n]=f(1)+f(2)+...+f(n),**f(i)表示以i为根节点的种数，**
4. **其中f(i)的左子树种数即i-1个节点形成的二叉树种数（用result[i-1]表示），**
   **其右子树种数即n-i个节点形成的二叉树种数（用result[n-i]表示），故f(i)=result[i-1]*result[n-i]**
   **result[n]=result[0]*result[n-1]+result[2]*result[n-2]+...+result[n-1]*reult[0]**
5. **特别要注意*reult[0]=1，表示左子树或右子树为空，但也是一种情况，与左或右子树只有一个节点一样**

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
       //创建一个数组
       vector<int> result(n+1);
       result[0]=1;
       result[1]=1;

       for(int i=2;i<=n;i++)
       {
           for(int j=1;j<=i;j++)
           {
               result[i]+=result[j-1]*result[i-j];
           }
       }
       return result[n];
    }
};
```