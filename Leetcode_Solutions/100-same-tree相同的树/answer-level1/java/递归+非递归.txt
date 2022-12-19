```
    /**
     *  非递归版本
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null) return true;
        if(p==null || q==null) return false;
        //用来存放以p为根节点的二叉树上的节点
        Queue<TreeNode> queueP=new LinkedList<TreeNode>();
        queueP.add(p);
        //用来存放以q为根节点的二叉树上的节点
        Queue<TreeNode> queueQ=new LinkedList<TreeNode>();
        queueQ.add(q);
        while(!queueP.isEmpty()){//当队列中仍然有节点时，执行循环体
            TreeNode nodeP=queueP.poll();//取出队列P中的第一个节点准备处理
            TreeNode nodeQ=queueQ.poll();//取出队列Q中的第一个节点准备处理

            //这个if分支用来处理两个二叉树，形状相同，但相同位置上的节点位置不同的情况
            if(nodeP.val!=nodeQ.val){//若两个节点的值不相同，则直接结束，表明两个二叉树上同一位置上的两个节点的值不同
                return false;
            }
            //下面两个if分支用来处理两个二叉树，形状不同的情况
            if(nodeP.left!=null && nodeQ.left!=null ){//只有当两个当前节点的左子节点都不为空时，将这个两个左子节点分别装入相应队列
                queueP.add(nodeP.left);
                queueQ.add(nodeQ.left);
            }else if(nodeP.left==null && nodeQ.left==null){//当两个当前节点的左子节点都为空时，不处理

            }else{//当两个当前节点只有一个当前节点存在左子节点时，说明形状不同，直接返回false
                return false;
            }

            if(nodeP.right!=null && nodeQ.right!=null ){//只有当两个当前节点的右子节点都不为空时，将这个两个右子节点分别装入相应队列
                queueP.add(nodeP.right);
                queueQ.add(nodeQ.right);
            }else if(nodeP.right==null && nodeQ.right==null){//当两个当前节点的右子节点都为空时，不处理

            }else{//当两个当前节点只有一个当前节点存在右子节点时，说明形状不同，直接返回false
                return false;
            }

        }
        return true;
    }
```

```
    /**
     *  递归版本
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null) return true;
        if(p==null || q==null) return false;
        return isSameTree(p.left,q.left) && isSameTree(p.right,q.right) && q.val==p.val;
    }
```

