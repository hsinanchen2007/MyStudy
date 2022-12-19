**耗时5ms**

```
class Solution {
    private List<Integer> mList;
    public boolean findTarget(TreeNode root, int k) {
        mList = new ArrayList<Integer>();
        inOrder(root);
        for(int i = 0; i<mList.size();i++){
            //受contains(k-key)和有序数组二分查找效率更高的启蒙
            if(search(mList,k-mList.get(i),i+1)){
                return true;
            }
        }
        return false;
    }
    public void inOrder(TreeNode node){
        if(node == null) return;
        inOrder(node.left);
        mList.add(node.val);
        inOrder(node.right);
    }
    public boolean search(List<Integer> list,int value,int leftOffset){
        int start = leftOffset;
        int end = list.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(list.get(mid) == value){
                return true;
            }else if(list.get(mid)<value){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }
}
```
