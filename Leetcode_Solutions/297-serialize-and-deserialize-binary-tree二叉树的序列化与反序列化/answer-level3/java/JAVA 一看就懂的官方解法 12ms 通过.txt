序列化：求二叉树的先序遍历序列
反序列化：通过序列化得到的先序遍历序列 构建原二叉树  
![IMG_20200224_142914.jpg](https://pic.leetcode-cn.com/611919e6b2284b54a5f87d374a9bfcaa1cafb7c22c869147808fa4853b095153-IMG_20200224_142914.jpg)

```
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder res=mySeri(root,new StringBuilder());
        return res.toString();
    }

    StringBuilder mySeri(TreeNode root,StringBuilder sb){
        if(root==null){
            sb.append("null,");
            return sb;
        }
        else if(root!=null){
            sb.append(root.val);
            sb.append(",");
            
            mySeri(root.left,sb);
            mySeri(root.right,sb);
        }
        return sb;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String []temp=data.split(","); // 将序列化的结果转为字符串数组
        List<String> list=new LinkedList<>(Arrays.asList(temp)); // 字符串数组转为集合类 便于操作
        return myDeSeri(list);
    }
    public TreeNode myDeSeri(List<String> list){
        TreeNode root;
        if(list.get(0).equals("null")){
            list.remove(0); // 删除第一个元素 则第二个元素成为新的首部 便于递归 
            return null;
        }
        else{
            root=new TreeNode(Integer.valueOf(list.get(0)));
            list.remove(0);
            root.left=myDeSeri(list);
            root.right=myDeSeri(list);
        }
        return root;
    }
}
```

