![Screen Shot 2020-01-14 at 7.52.04 PM.png](https://pic.leetcode-cn.com/1317df91be6bb2551345e24ce4df4101baffd53b19c45068916372f083c7203f-Screen%20Shot%202020-01-14%20at%207.52.04%20PM.png)

自定义了一个数据结构，用来储存层数和对应位置。
```
public int widthOfBinaryTree(TreeNode root) {
        Queue<data> queue = new LinkedList<>();
        if(root==null){
            return 0;
        }
        data one = new data(root,0,0);
        queue.add(one);
        int layer = 0;
        int ans = 1;
        int start = 0;
        int end = 0;
        while(!queue.isEmpty()){
            data temp = queue.poll();
            if(layer!=temp.layer){
                ans = Math.max(end-start+1,ans);
                start = temp.count;
                end = start;
                layer += 1;
            }
            else{
                end = temp.count;
            }
            if(temp.node.left!=null){
                queue.add(new data(temp.node.left,temp.layer+1,temp.count*2));
            }
            if(temp.node.right!=null){
                queue.add(new data(temp.node.right,temp.layer+1,temp.count*2+1));
            }
        }
        return Math.max(end-start+1,ans);
    }

    class data{
        TreeNode node;
        int layer;
        int count;
        public data(TreeNode node,int layer,int count){
            this.node = node;
            this.count = count;
            this.layer = layer;
        }
    }
```

