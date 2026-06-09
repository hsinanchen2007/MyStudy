递归加加剪枝，回溯添加到k个元素的时候返回，不再回溯。
```
class Solution {
    int count=0;
    public int kthSmallest(TreeNode root, int k) {
       ArrayList<Integer> al=inorder(root,new ArrayList<Integer>(),k);
        return al.get(k-1);
    }
    ArrayList<Integer> inorder(TreeNode root,ArrayList<Integer> arr,int m){
        if(root==null){
            return arr;
        }
        
        inorder(root.left,arr,m);
        arr.add(root.val);
        count++;
        if(count==m){
            return arr;
        }
        inorder(root.right,arr,m);
        return arr;
    }
}
```

