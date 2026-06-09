栈和队列用得不熟，还是用集合做的，想了好久
```
    public List<Integer> postorder(Node root) {
        List<Integer> nums = new LinkedList<>();
        List<Node> list = new ArrayList<>();
        list.add(root);
        int i=0;
        while (i<list.size()) {
            Node node = list.get(i);
            if(node!=null){
                List<Node> child = node.children;
                if(child!=null&&child.size()>0){
                    for(int j=child.size()-1;j>-1;j--){
                        list.add(i+child.size()-j,child.get(j));
                    }
                }
            }else {
                return nums;
            }
            i++;
        }
        for (Node node : list) {
            nums.add(0,node.val);
        }
        return nums;
    }
```
