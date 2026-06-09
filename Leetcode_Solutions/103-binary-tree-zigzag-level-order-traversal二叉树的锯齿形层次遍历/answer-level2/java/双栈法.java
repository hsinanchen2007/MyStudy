由于是锯齿输出：广度优先+从左向右/从右向左。因此想到用能够反序的栈作为载体。
于是设置栈s1和栈s2，s1的作用在于接收s2出栈节点的子节点（左右），s2用于接收s1出栈节点的子节点（右左）。s1和s2的出栈为最后的结果。
过程如下：

![IMG_7FD195F163ED-1.jpeg](https://pic.leetcode-cn.com/d49b2e27089d6eee4ce14f185c7e12c2f8463e73af856993ab39d4b31cf70338-IMG_7FD195F163ED-1.jpeg)
代码：


        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        
        List<List<Integer>> res = new LinkedList<>();
        
        if(root == null) return res;
        
        s1.push(root);
        
        while(!s1.isEmpty() || !s2.isEmpty()){
            List<Integer> l1 = new ArrayList<>();
            while(!s1.isEmpty()){
                TreeNode tn = s1.pop();
                if(tn != null) {
                    l1.add(tn.val);
                    s2.push(tn.left);
                    s2.push(tn.right);
                }
            }
            if(l1.size() > 0 )res.add(l1);
            
            List<Integer> l2 = new ArrayList<>();
            while(!s2.isEmpty()){
                TreeNode tn = s2.pop();
                if(tn != null){
                    l2.add(tn.val);
                    s1.push(tn.right);
                    s1.push(tn.left);  
                } 
            }
            if(l2.size() > 0) res.add(l2);
            if(s1.isEmpty() && s2.isEmpty()) break;     
        }
       
        return res;
