 if(root==null)
        {
            return true;//防止空树
        }
        Queue<TreeNode> q = new Queue<TreeNode>();
            q.Enqueue(root.left);
            q.Enqueue(root.right);
            //和递归思路相同
            while(!(q.Count==0))
            {
                TreeNode t1 = q.Dequeue();
                TreeNode t2 = q.Dequeue();
                if (t1 == null&&t2==null)
                {
                    continue;
                }
                if(t1==null||t2==null)
                {
                    return false;
                }
                if(t1.val!=t2.val)
                {
                    return false;
                }
                q.Enqueue(t1.left);
                q.Enqueue(t2.right);
                q.Enqueue(t1.right);
                q.Enqueue(t2.left);
            }
            return true;
//队列顺序:1:2,2 2=2 
           2:3,3,4,4  3=3
           3:4,4,5,5,6,6  4=4
           4:5,5,6,6,7,7,7,8,8  5=5
           5:6,6,7,7,7,8,8,null,null  6=6
      后面类似，队列顺序的比较和递归还是不一样的  递归比的是最左节点和最右节点的值 如果为空则返回比上一左节点的右节点
和右节点的左节点