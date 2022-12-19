/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/30
 *
 * 解题思路: 递归 判断到根节点的话输出 思想为先序遍历 注意：判断一下开始的 "->"
 */
```
List<String> list = new ArrayList<String>();

public List<String> binaryTreePaths(TreeNode root) {
    binaryTreePathsExe(root , "");
    return list;
}

public void binaryTreePathsExe(TreeNode root , String s) {

    if(root == null){
        return;
    }else if(root.left == null && root.right == null){
        s = s + "->" + root.val;
        if(s.substring(0,2).equals("->")){
            s = s.substring(2);
        }
        list.add(s);
        return;
    }else {
        s += "->" + root.val;
        binaryTreePathsExe(root.left, s);
        binaryTreePathsExe(root.right , s);
    }
}
```