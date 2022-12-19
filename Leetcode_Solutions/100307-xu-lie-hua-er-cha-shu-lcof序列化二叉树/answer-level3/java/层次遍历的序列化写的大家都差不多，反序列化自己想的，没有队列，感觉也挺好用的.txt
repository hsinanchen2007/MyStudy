    
    public class Codec {

        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            StringBuilder sb = new StringBuilder();
            sb.append("[");
            while(!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if(node != null) {
                    sb.append(node.val + ",");
                    queue.add(node.left);
                    queue.add(node.right);
                }else {
                    sb.append("null,");
                }
            }
            sb.deleteCharAt(sb.length() - 1);
            sb.append("]");
            return sb.toString();
        }

        // Decodes your encoded data to tree.
        // 反序列化自己想的，不用队列直接用list，感觉也挺好用的，遍历到每个节点，将其left和right连好
        public TreeNode deserialize(String data) {
            StringBuilder sb = new StringBuilder(data);
            sb.deleteCharAt(0);
            sb.deleteCharAt(sb.length() - 1);
            String[] str = sb.toString().split(",");
            List<TreeNode> list = new LinkedList<>();
            for (String s : str) {
                list.add("null".equals(s) ? null : new TreeNode(Integer.parseInt(s)));
            }
            int index = 0;
            TreeNode head = list.get(0);
            for(int i = 0;i < list.size();i++) {
                TreeNode temp = list.get(i);
                if(temp != null) {
                    temp.left = list.get(++index) == null ? null : list.get(index);
                    temp.right = list.get(++index) == null ? null : list.get(index);
                }
            }
            return head;
        }
    }