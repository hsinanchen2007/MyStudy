```
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
    public int[] findFrequentTreeSum(TreeNode root) {
        if (root==null){
            return new int[0];
        }
        Map<Integer,Integer> map=new HashMap<>();
        PriorityQueue<Integer> queue=new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return map.get(o2)-map.get(o1);
            }
        });
        dfs(root,queue,map);
        List<Integer> list=new ArrayList<>();
        int max=queue.peek();
        while (!queue.isEmpty()){
            if (map.get(queue.peek())>=map.get(max)){
                list.add(queue.peek());
                queue.poll();
            }else {
                break;
            }
        }
        int[] ans=new int[list.size()];
        for (int i=0;i<list.size();i++){
            ans[i]=list.get(i);
        }
        return ans;
    }
    public int dfs(TreeNode root,PriorityQueue<Integer> queue,Map<Integer,Integer> map) {
        if (root==null){
            return 0;
        }
        int left=dfs(root.left,queue,map);
        int right=dfs(root.right,queue,map);
        int value=left+right+root.val;
        if (map.containsKey(value)){
            map.put(value,map.get(value)+1);
        }else {
            map.put(value,1);
            queue.offer(value);
        }
        return value;
    }
}
```
