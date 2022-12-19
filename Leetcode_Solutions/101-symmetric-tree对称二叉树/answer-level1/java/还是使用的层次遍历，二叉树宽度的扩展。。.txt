class Solution {
    //仍然利用二叉树宽度的思想：将每层节点（包括空节点入null进入）[[1], [2, 2], [null, 3, null, 3], [null, null, null, null]]
    public List<List<String>> lists=new ArrayList();
    public List<List<String>> getleverNodes(TreeNode root){
        if(root!=null){
            Queue<TreeNode> queue=new LinkedList();
            queue.add(root);
            while(!queue.isEmpty()){
                int currentSize=queue.size();
                List<String> list=new ArrayList();
                for(int i=0;i<currentSize;i++){
                    TreeNode p=queue.poll();
                    if(p!=null){
                        queue.add(p.left);
                        queue.add(p.right);
                        list.add(String.valueOf(p.val));
                    }else{
//                   空节点也要入队  后面也要比较
                    list.add("null");
                    }
                }
                lists.add(list);
            }
        }
        return lists;
    }
    //判断是否是对称的  使用两个索引，一个在头一个在尾 进行比较。
    public boolean panduan(List<List<String>> lists){
        //头节点不用判断，就自己一个  i从1开始就行
       for(int i=1;i<lists.size()-1;i++){
            List<String> list=lists.get(i);
           //左后的string集合是null  不用对比，所以<list.size()-1
            for(int m=0,n=list.size()-1;m<=n;){
                if(list.get(m).equals(list.get(n))){
                    m=m+1;
                    n=n-1;
                }else {
                    return false;
                }
            }
        }
        return  true;
    }
    public boolean isSymmetric(TreeNode root) {
        lists=getleverNodes(root);
        return panduan(lists);
    }
}