1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为 $O(n)$
<br />&nbsp;1.2 空间负责度为 $O(1)$
2. 我的解题思路
<br />&nbsp;2.1 我觉得这道题的关键是在 BST 上，中序遍历 BST 可以得到升序的数组，而这个意味着我们可以利用升序数组的特性进行解题
<br />&nbsp;2.2 定义四个变量
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.2.1 list，用来存储最终结果
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.2.2 pre，上一个遍历的元素
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.2.3 cnt，当前元素重复的次数
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.2.4 max，当前最大的元素重复次数
<br />&nbsp;2.3 传统中序遍历，只是遍历当前节点的值进行我们的众数的求解，分为两个情况
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.3.1 pre 等于当前节点的值，cnt 加 1
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.3.2 pre 不等于当前节点的值，cnt 置 1，pre 置为当前节点的值
<br />&nbsp;2.4 对比 cnt 以及 max 的值，有两种情况
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.4.1 cnt=max，将 pre 加入到结果 list 中
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.4.2 cnt>max，新的众数诞生，清空当前 list，将 pre 加入到 list 中
3. 提交记录
<br />&nbsp;3.1 力扣中耗时 2ms,消耗 41.4MB 内存
<br />&nbsp;3.2 leetcode 中耗时 1ms,消耗 37.8MB 内存
4. Q&A

```
/**
 * Problem
 *     501. Find Mode in Binary Search Tree
 *     https://leetcode.com/problems/find-mode-in-binary-search-tree/
 *     https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {
    
    private List<Integer> list;
    
    private int pre;
    
    private int cnt;
    
    private int max;
    
	/**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 I think the key of this topic is BST,inOrder traverse will get the ASC array,it means we can cal mode with this sequence
     *     2.2 define four variable
     *         2.2.1 list,record final result
     *         2.2.2 pre,record last traverse node's val
     *         2.2.3 cnt,current mode count
     *         2.2.4 max,maximum count of mode
     *     2.3 traditional inOrder traversal,only operate with current node'val,there have two condition
     *         2.3.1 pre is equals current val,set cnt to cnt+1
     *         2.3.2 pre isn't equals current val,set cnt to 1,pre to current val
     *     2.4 compare cnt to max,there have two condition to operate
     *         2.4.1 cnt==max,add pre to result list
     *         2.4.2 cnt>max,clear list and add pre to result list
     * 3.About submit record
     *     3.1 2ms and 41.4MB memory in LeetCode China
     *     3.2 1ms and 37.8MB memory in LeetCode
     * 4.Q&A
     * @param root
     * @return
     */
    public int[] findMode(TreeNode root) {
        if(root==null){
            return new int[0];
        }
        list=new LinkedList<>();
        inOrder(root);
        int[] res=new int[list.size()];
        for(int i=0,size=list.size();i<size;i++){
            res[i]=list.get(i);
        }
        return res;
    }
    
    private void inOrder(TreeNode root){
        if(root==null){
            return;
        }
        inOrder(root.left);
        if(pre==root.val){
            cnt++;
        }
        else{
            cnt=1;
            pre=root.val;
        }
        if(cnt==max){
            list.add(root.val);
        }
        else if(cnt>max){
            list.clear();
            list.add(root.val);
            max=cnt;
        }
        inOrder(root.right);
    }
}
```


