### 解题思路
厚

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    //序列化：前向遍历过程
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeHelper(root,sb);
    //    System.out.println(sb.toString());
        return sb.toString();
    }
    public void serializeHelper(TreeNode root,StringBuilder sb){
        if(root == null){
            sb.append('$');
            sb.append(',');
        }else{
            sb.append(root.val);
            sb.append(',');
            serializeHelper(root.left,sb);
            serializeHelper(root.right,sb);
        }
    }

    // Decodes your encoded data to tree.
    //反序列化：
    public TreeNode deserialize(String data) {
        if(data.length()<=0)return null;
        //用一个数组存当前未遍历字符的第一个位置
        int[] pos = {0};
        return deserializeHelper(data,pos);
    }
    public TreeNode deserializeHelper(String data,int[] pos){
        //‘¥’返回null
        if(data.charAt(pos[0])=='$'){
            pos[0]+=2;
            return null;
        }
        else{
//模拟前序遍历建树：
            //flag判断是否是负数，循环求当前节点数字，直到碰到逗号
            int flag = 0;
            int num = 0;
            if(data.charAt(pos[0])=='-'){flag = 1;pos[0]++;}
            while(data.charAt(pos[0])>='0'&&data.charAt(pos[0])<='9'){
                num*=10;
                num+=(data.charAt(pos[0])-'0');
                pos[0]++;
            }
            num = flag==1?-num:num;
           
            TreeNode root = new TreeNode(num);
            pos[0]++;
            root.left = deserializeHelper(data,pos);
            root.right = deserializeHelper(data,pos);
            return root;
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```