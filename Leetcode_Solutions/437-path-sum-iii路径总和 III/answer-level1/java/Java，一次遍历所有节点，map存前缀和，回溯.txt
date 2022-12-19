### 解题思路

![捕获.JPG](https://pic.leetcode-cn.com/cf88d3ff9e1d18209b6faf60e806c4c4ae8adf6bcd80cea0265afe407d5b2ff4-%E6%8D%95%E8%8E%B7.JPG)

思路类似560题的hashmap的解法[https://leetcode-cn.com/problems/subarray-sum-equals-k/]()
 首先理解求数组中和为k的子数组的总数
 定义sum[i]代表0~i下标的元素和
 j>i时   i至j的元素和可以由两个前缀和求得:  sum[j]-sum[i]
 即sum[j]-sum[i]=k时 count+1
 所以也可以利用 sum[j]-k=sum[i] 求总数, 总数再加上sum[i]出现得次数即可,而 sum[i]出现得次数可以用map存起来。
对于树，和求数组中和为k的子数组不同的是要回溯，走过得路径要回退。
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public int pathSum(TreeNode root, int sum) {
        Map<Integer,Integer> m = new HashMap<>();
        m.put(0,1);//即当前路径和是目标数
        return travel(root,sum,m,0,0);
    }

    // targetSum  目标和
    //m  保存到该节点以前 前缀和出现的次数
    // pathSum  到该节点之前路径和 即前缀和
    // sum       满足目标和的路径 总数
    Integer travel(TreeNode n,int targetSum,Map<Integer,Integer> m,int pathSum,Integer sum){
        if(n==null){
            return sum;
        }
        int prefixSum=pathSum+n.val;
        if(m.containsKey(prefixSum-targetSum)){     //利用前缀和s[k]代表路径从根到k的和, j>i  s[j]-s[i]=targetSum  时 sum+1
            sum+=m.get(prefixSum-targetSum);        //   得出      s[j]-targetSum=s[i]时      sum+ （s[i] 出现的次数）
        }
        if(m.containsKey(prefixSum)){
            m.put(prefixSum,m.get(prefixSum)+1);
        }else {
            m.put(prefixSum,1);
        }

        if(n.left!=null){
            sum=travel(n.left,targetSum,m,prefixSum,sum);

        }
        if(n.right!=null){
            sum=travel(n.right,targetSum,m,prefixSum,sum);
        }

        //状态恢复   //回溯
        m.put(prefixSum,m.get(prefixSum)-1);
        return sum;
    }
}
```