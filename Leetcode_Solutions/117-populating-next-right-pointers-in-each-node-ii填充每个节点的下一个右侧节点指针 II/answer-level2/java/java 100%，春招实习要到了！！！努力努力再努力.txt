
主要是记住上一个节点，并指向下一个存在的节点，没有就一直往右找
在进入下一层的时候，可能初始保存的那个节点没有孩子，所以要一直找到可行的节点
```
class Solution {
    public Node connect(Node root) {
        if(root==null)return root;
        Node leftfirst=root;
        Node pre=null;//用来记录本层的前一个节点
        while(leftfirst!=null){
            Node lefttemp=leftfirst;//每一层从最左边开始找，要记住，不然没法进入下一层,
            pre=null;//本层当前节点的前一个节点，每层开始时为空
            while(lefttemp!=null){//上层节点不为空，说明还没结束
                if(lefttemp.left!=null){//找到可行的节点，是左孩子
                    if(pre==null){//本层初始有效节点
                        pre=lefttemp.left;
                    }else{//不为空说明本层已经有有效节点了，直接将前一个节点指向当前节点
                        pre.next=lefttemp.left;
                        pre=lefttemp.left;//一定要更新
                    }
                }
                if(lefttemp.right!=null){
                    if(pre==null){//本层初始有效节点
                        pre=lefttemp.right;
                    }else{
                        pre.next=lefttemp.right;
                        pre=lefttemp.right;
                    }
                }
                lefttemp=lefttemp.next;//继续找下一个节点的有效节点
            }
            //要找到下一层不为空的节点就可以进入下一层
            while(leftfirst!=null){
                if(leftfirst.left !=null){
                    leftfirst=leftfirst.left;//可以进入下一层
                    break;
                }else if(leftfirst.right!=null){
                    leftfirst=leftfirst.right;
                    break;
                }else{
                    leftfirst=leftfirst.next;//继续在next节点中找能进入下一层的
                }
            }    
        }
        return root;
        
    }
}
```
