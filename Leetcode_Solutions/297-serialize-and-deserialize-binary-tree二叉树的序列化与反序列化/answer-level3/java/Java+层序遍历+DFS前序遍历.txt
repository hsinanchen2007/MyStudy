## 1. 层序遍历解法
### 解题思路（忽略了一些细节）：
1. 序列化：层序遍历，并按层存放：层之间用 ","隔开，节点之间用 "#"隔开
2. 反序列化：上层节点提前入队。遍历当前层节点：步长为2，构建两个节点，上层节点出队，其左右孩子指针分别指向这两个节点。然后循环即可

## 2. DFS：前序遍历解法
### 解题思路：
1. 序列化：前序遍历存储即可
2. 递归反序列化：
	1. 功能：传入经过切割处理的字符串数组 /List，建树，返回树的根节点
	2. 流程：
		1. 判断本层递归是否结束
		2. 建立 根节点，并删除list项
		3. 将剩余list作为参数继续递归，将左孩子指向返回值即可；
		4. 将剩余list作为参数继续递归，将左孩子指向返回值即可；
		5. 返回根节点
	3. 结束条件：List为空，返回 null

### 层序遍历代码

```java []
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) { //层序遍历;分层存放
        if(root==null){return "null";}
        StringBuilder str=new StringBuilder();
        //辅助队列
        Queue<TreeNode> queue=new LinkedList();
        queue.add(root);str.append(root.val);
        //遍历
        while(!queue.isEmpty()){
            str.append(",");
            for(int i=queue.size();i>0;--i){
                TreeNode p=queue.poll(); //出队
                if(p.left!=null){
                    queue.add(p.left);
                    str.append("#"+p.left.val);
                }else{
                    str.append("#null");
                }
                if(p.right!=null){
                    queue.add(p.right);
                    str.append("#"+p.right.val);
                }else{
                    str.append("#null");
                }
            }
        }
        // System.out.println(str);
        return str.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if("null".equals(data)){return null;}
        String[] layers=data.split(","); //分割层
        Queue<TreeNode> queue=new LinkedList(); //辅助队列
        TreeNode root=new TreeNode(Integer.parseInt(layers[0])); //初始化队列
        queue.add(root);
        for(int i=1;i<layers.length;++i){ //按层遍历
            String layer=layers[i].substring(1);
            String[] nodes=layer.split("#");
            for(int j=0;j<nodes.length;j+=2){ //遍历每层的每两个节点
                TreeNode lastP=queue.poll();TreeNode p;
                if(!"null".equals(nodes[j])){
                    p=new TreeNode(Integer.parseInt(nodes[j]));
                    lastP.left=p;
                    queue.add(p);
                }else{
                    lastP.left=null;
                }
                if(!"null".equals(nodes[j+1])){
                    p=new TreeNode(Integer.parseInt(nodes[j+1]));
                    lastP.right=p;
                    queue.add(p);
                }else{
                    lastP.right=null;
                }
            }
        }
        return root;
    }
}
```