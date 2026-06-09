while (true){
            if (p != null && q != null){
                if (p.val == q.val){
                    return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
                }else{
                    return false;
                }
            }else if (p == null && q == null){
                return true;
            }else{
                return false;
            }
        }