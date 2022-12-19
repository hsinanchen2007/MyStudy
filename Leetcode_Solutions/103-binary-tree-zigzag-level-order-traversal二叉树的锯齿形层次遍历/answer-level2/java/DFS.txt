![image.png](https://pic.leetcode-cn.com/488f62149ce7cf9f302658a448e95a69a811a202b703982f22a49a6b0368aad0-image.png)

```
//先正常遍历，再把奇数项颠倒
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> answer;
        int i;
        
        answer = new ArrayList<>();
        zigzagLevelOrderHelper(root, 0, answer);
        for(i = 1; i < answer.size(); i = i + 2){
            reverse(answer.get(i));
        }
        return answer;
    }
    
    private void reverse(List<Integer> list){
        int i, j, t;
        
        i = 0;
        j = list.size() - 1;
        while(i < j){
            t = list.get(i);
            list.set(i, list.get(j));
            list.set(j, t);
            i++;
            j--;
        }
    }
    
    private void zigzagLevelOrderHelper(TreeNode root, int depth, List<List<Integer>> values){
        List<Integer> value;
        
        if(root != null){
            if(values.size() <= depth){
                value = new ArrayList<>();
                value.add(root.val);
                values.add(value);
            }
            else{
                value = values.get(depth);
                value.add(root.val);
            }
            zigzagLevelOrderHelper(root.left, depth + 1, values);
            zigzagLevelOrderHelper(root.right, depth + 1, values);
        }   
    }
}
```
