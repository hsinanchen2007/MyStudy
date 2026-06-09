
- 本题思路简单：递归实现找叶子。将每一个找到的路径写进StringBuilder 的list中。需要注意两个问题：
1. 二进制字符串转int，可直接用接口
2. ！！！java中传参，若是引用类型，传的本质是指针，所以要保留原始数据（temp）



```
class Solution {
    List <StringBuilder> leafSB = new ArrayList();
    
    public int sumRootToLeaf(TreeNode root) {
        int result = 0;
        
        StringBuilder sb = new StringBuilder();
        
        findNum(root,sb);
        int length = leafSB.size();
        
        for(int i=0; i<length;i++)
        {
            String temp = new String(leafSB.get(i));
            result += Integer.parseUnsignedInt(temp,2);
        }

        return (result);
    }
     
    public void findNum(TreeNode root, StringBuilder nowSB)
    {
        if(root.left != null && root.right != null)
        {
            nowSB.append(root.val);
            StringBuilder temp = new StringBuilder(nowSB);
            findNum(root.left, nowSB);
            findNum(root.right, temp);
        }
        else if(root.left == null && root.right != null)
        {
            nowSB.append(root.val);
            findNum(root.right, nowSB);
        }
        else if(root.left != null && root.right == null)
        {
            nowSB.append(root.val);
            findNum(root.left, nowSB);
        }
        else
        {
            nowSB.append(root.val);
            leafSB.add(nowSB);
            return ;
        }
    }
}
```
