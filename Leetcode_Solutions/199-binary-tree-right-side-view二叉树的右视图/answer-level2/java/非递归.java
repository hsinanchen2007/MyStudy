class Solution {

        List<Integer> ret=new ArrayList();
        public List<Integer> rightSideView(TreeNode root) {
            if(root==null)
                return ret;
            List<TreeNode> list=new LinkedList();
            list.add(root);
            while(!list.isEmpty()){
                int len=list.size();
                for(int i=0;i<len;i++){
                    TreeNode tem=list.remove(0);
                    if(tem.left!=null)
                        list.add(tem.left);
                    if(tem.right!=null)
                        list.add(tem.right);
                    if(i==len-1)
                        ret.add(tem.val);
                }
            }
            return ret;
        }
    }