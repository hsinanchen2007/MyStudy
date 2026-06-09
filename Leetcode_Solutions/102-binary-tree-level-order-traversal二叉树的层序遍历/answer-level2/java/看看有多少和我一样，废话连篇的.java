看看，大家参考一下

public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList();
        List<Integer> temp = new ArrayList();
        List<TreeNode> countPre = new ArrayList<>();
        List<TreeNode> countAfter = new ArrayList<>();
        if(root != null) {
            temp.add(root.val);
            result.add(temp);
            countPre.add(root);
        }

        boolean flag = true;
        while(flag) {
            temp = new ArrayList<>();
            countAfter.clear();
            //遍历每一层级的下一层，不为null装入countAfter
            for (int i = 0; i < countPre.size(); i++) {
                TreeNode t = countPre.get(i);
                if (t.left != null) {
                    temp.add(t.left.val);
                    countAfter.add(t.left);
                }
                if (t.right != null) {
                    temp.add(t.right.val);
                    countAfter.add(t.right);
                }
            }
            
            if (temp.size() != 0) {
                result.add(temp);
            }

            countPre.clear();
            for(TreeNode tn : countAfter) {
                countPre.add(tn);
            }

            if(countAfter.size() == 0) {
                flag = false;
            }
        }

        return result;
}