因为题目要求我们要返回所有从根节点到叶子节点路径总和等于目标值的路径，因此我们需要有一个list来存储每条路径所包含的节点，我们不用为每条路径path都创建一个新的list，这样会很浪费空间和时间，我们在递归时可以传递list的*引用*，再通过**回溯**的方法来确保path的正确性，即*每次访问完一条路径后，回溯，即删除list的最后一个元素，让path恢复到正确的状态*，再接着另一条路径的访问。
<br>

```
public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> paths=new ArrayList<List<Integer>>();
        go(root,0,sum,new ArrayList<Integer>(),paths);
        return paths;
    }
    
    void go(TreeNode node,int sum,int target,ArrayList<Integer> path,List<List<Integer>> paths){
        if(node==null)return;
        sum+=node.val;
        path.add(node.val);
        //判断该路径和是否符合目标值
        if(sum==target&&node.left==null&&node.right==null){
            paths.add(new ArrayList<Integer>(path));
        }else{
            go(node.left,sum,target,path,paths);
            go(node.right,sum,target,path,paths);
        }
        //回溯
        path.remove(path.size()-1);
    }
```
