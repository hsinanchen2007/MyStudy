这个思想可以做一系列的 关于平衡的问题
这道题:我们需要考虑
1. 左子树是否平衡       不平衡直接返回false
2. 右子树是否平衡       不平衡直接返回false
3. 左树的高度
4.                      高度差的绝对值大于1.false
4. 右树的高度
```java 
    //返回的种类,有是否平衡,和高度
    static class ReturnType{
        boolean isB;
        int height;

        public ReturnType(boolean b,int h){
            this.isB = b;
            this.height=h;

        }

    } 
    //主函数,以为只要一个boolean类型的
    public boolean isBalanced(TreeNode root) {
        return process(root).isB;
    }
    

    public ReturnType process(TreeNode head){
        if(head==null){
            return new ReturnType(true,0);
        }
        ReturnType leftType = process(head.left);
        if(!leftType.isB){
            return new ReturnType(false,0);
        }
        ReturnType rightType =process(head.right);
        if(!rightType.isB){
            return new ReturnType(false,0);
        }
        if(Math.abs(leftType.height-rightType.height)>1){
            return new ReturnType(false,0);
        }
        return new ReturnType(true,Math.max(leftType.height,rightType.height)+1);
    }
```

