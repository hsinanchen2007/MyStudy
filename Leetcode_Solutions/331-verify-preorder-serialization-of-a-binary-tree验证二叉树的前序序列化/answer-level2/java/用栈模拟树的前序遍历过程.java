定义一个class Pair记录栈中元素，一个pair包含表示节点的String 和一个boolen当前遍历的方向。  
两种情况:  
1. 遇到非#，构造一个pair,方向为left(true)，入栈，表示向左子树往下
2. 遇到#，表示到了底部，要pop，查看父节点，如果父节点是往左向下即way=true,就改为false,将父节点入栈。如果父节点的方向是右，则表示父节点的两个子数都遍历完成，父节点要结束遍历。还要对父节点的父节点检查方向，直到遇到根节点或者祖父节点是向左的。
```
import java.util.LinkedList;

class Pair{
    String node;
    boolean way;
    Pair(String node,boolean way){
        this.node = node;
        this.way = way;
    }
    public String toString(){
        return node+","+way;
    }
}

class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] eles = preorder.split(",");
        LinkedList<Pair> stk = new LinkedList<>();
        for(int i = 0;i<eles.length;++i){
            String ele = eles[i];
            if(!ele.equals( "#")){//节点
                stk.push(new Pair(ele,true));//左边下去
            }
            else//#
            {
                while(true){
                    if(stk.isEmpty()){
                        if(i != eles.length - 1)
                            return false;
                        else
                            return true;
                    }
                    else{
                        Pair top = stk.peek();
                        if(top.way == true){
                            top.way = false;
                            break;
                        }
                        else{
                            stk.pop();//删除这个节点，继续pop
                        }
                    }
                }
            }
        }
        if(stk.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }

    // public static void main(String[]args){
    //     Solution solution = new Solution();
    //     System.out.println(solution.isValidSerialization("9,#,#,1"));
    // }
}
```
