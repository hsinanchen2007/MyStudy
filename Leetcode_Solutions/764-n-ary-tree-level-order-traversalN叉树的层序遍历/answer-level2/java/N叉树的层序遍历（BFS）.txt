## 思路
    简单的广度优先搜索。用一个List维护同一层的节点，cur变量维护当前层节点数量，next变量维护下层节点数量。每次从队列中取出是，cur--,每次将当前层节点的儿子节点加入队列时，next++，当cur变量减为0时，当前层的节点访问完毕，将next付给cur，访问下一层的节点
## 代码
```
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res=new ArrayList<>();
        if(root==null)
            return res;
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        int cur=1;
        int next=0;
        List<Integer> helper=new ArrayList<>();
        while(!q.isEmpty()){
            Node temp=q.poll();
            cur--;
            helper.add(temp.val);
            for(Node child:temp.children){
                q.add(child);
                next++;
            }
           
            if(cur==0){
                res.add(new ArrayList<>(helper));
                helper.clear();
                cur=next;
                next=0;
            }
        }
        return res;
    }
```