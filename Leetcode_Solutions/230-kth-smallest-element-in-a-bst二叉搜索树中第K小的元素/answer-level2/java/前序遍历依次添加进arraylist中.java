
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        list(root,arr);
        Collections.sort(arr);
        int value = 0;
        value = arr.get(k-1);
        return value;
    }
    public void list(TreeNode root,ArrayList<Integer> arr){
        arr.add(root.val);
        if(root.left!=null)
            list(root.left,arr);
        if(root.right!=null)
            list(root.right,arr);
         }
    } 
