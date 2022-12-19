### 解题思路
方法一: 双队列实现层次遍历
思路：
1. 结果需要自底向上，直接自底向上显然不好实现，所以可以采用自顶向下层次遍历，然后再反转即可得到。
2. 如果用一个队列进行层次遍历，会有一个麻烦，就是不知道每一层什么时候结束，就没办法将每一层的数据分别用不同集合来存储。
3. 所以可以采用两个队列来实现，一个队列遍历当前层，一个队列存储下一层，交替使用，达到目的。


[个人博客地址](http://47.101.136.180/)

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) {
        	return list;
        }
    	
        Queue<TreeNode> queue1 = new LinkedList<>();
        Queue<TreeNode> queue2 = new LinkedList<>();
        
        queue1.offer(root);
        
      //如果未遍历完，则一定有一个队列不为空，一个为空
        while(!queue1.isEmpty() || !queue2.isEmpty()) {
        	//创建一个集合来存储当前层的数据
        	List<Integer> sub = new ArrayList<>();
        	
        	if (!queue1.isEmpty()) {//queue1不为空，则存储当前层数据
        		while(!queue1.isEmpty()) { //遍历当前层
        			TreeNode cur = queue1.poll();
        			
        			sub.add(cur.val); //将当前层元素添加到集合中
        			
        			//如果子节点不为空则将子节点添加到另一个队列中
        			if (cur.left != null) {
        				queue2.offer(cur.left);
        			}
        			if (cur.right != null) {
        				queue2.offer(cur.right);
        			}
        		}
        	} else {//queue2存储当前层数据
        		while(!queue2.isEmpty()) {
        			TreeNode cur = queue2.poll();
        			sub.add(cur.val);
        			if (cur.left != null) {
        				queue1.offer(cur.left);
        			} 
        			if (cur.right != null) {
        				queue1.offer(cur.right);
        			}
        		}
        	}
        	//将这一层的数据添加到结果集合中
        	list.add(sub);
        }
        //反转
        Collections.reverse(list);
        return list;
    }
}
```

### 解题思路
方法二: 深搜实现层次遍历
使用深搜来实现层次遍历的核心就是必须记录住当前是第几层，只有知道了当前是第几层才能往对应层的集合添加数据

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
    	List<List<Integer>> list = new ArrayList<>();
    	if (root == null) {
        	return list;
        }
    	//深搜
    	dfs(root, 0, list);
    	
    	//反转
    	Collections.reverse(list);
    	return list;
    }

	private void dfs(TreeNode root, int lelve, List<List<Integer>> list) {
		if (root == null) {
			return ;
		}
		
		if (list.size() <= lelve) {
			//说明当前层，还没有开始存数据,进行初始化
			list.add(lelve, new ArrayList<Integer>());
		}
		//将当前节点的数据存储到当前层
		list.get(lelve).add(root.val);
		
		//继续遍历遍历下一层的数据
		dfs(root.left, lelve + 1, list);
		dfs(root.right, lelve + 1, list);
	}
}
```