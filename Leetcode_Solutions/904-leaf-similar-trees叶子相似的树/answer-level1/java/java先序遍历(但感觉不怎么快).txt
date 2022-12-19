```
public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1=new ArrayList<>();
        List<Integer> list2=new ArrayList<>();
        preRootTraverse(root1,list1);
        preRootTraverse(root2,list2);
        return list1.equals(list2);
    }

public void preRootTraverse(TreeNode root,List<Integer> list){
        if(root!=null){
            if(root.left==null&&root.right==null){
                list.add(root.val);
            }
            preRootTraverse(root.left,list);
            preRootTraverse(root.right,list);
    }
}
```
  

  
![TIM截图20191124163922.png](https://pic.leetcode-cn.com/0dd1b143ccdec09dad826c30bb915d0657cae3d97d8ec44ef29c07b92ce4488a-TIM%E6%88%AA%E5%9B%BE20191124163922.png)

