递归中序遍历，无额外存储空间。

```
class Solution {
    int max = 0;
    List<Integer> modes = new LinkedList<>();
    int currentValue;
    int count;

    public int[] findMode(TreeNode root) {
        if (root == null){
            return new int[0];
        }
        currentValue = root.val;
        count = 0;

        helper(root);
        int[] result = new int[modes.size()];
        for (int i=0;i<modes.size();i++){
            result[i] = modes.get(i);
        }
        return result;
    }

    public void helper(TreeNode root){
        if (root == null){
            return;
        }
        helper(root.left);
        if (currentValue == root.val){
            count++;
        }else if(currentValue!=root.val){
            count=1;
            currentValue = root.val;
        }

        if (count==max){
            modes.add(currentValue);
        }else if (count>max){
            max = count;
            modes.clear();
            modes.add(currentValue);
        }

        helper(root.right);

    }
}
```