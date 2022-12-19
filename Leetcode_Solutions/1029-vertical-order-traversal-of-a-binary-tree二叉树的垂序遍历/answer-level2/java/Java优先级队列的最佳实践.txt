练习优先级队列非常好的题目，被排序搞的痛不欲生

```

public class State {

    public TreeNode node;
    public int position;
    public int level;

    public State(TreeNode node, int position, int level){
        this.level = level;
        this.node = node;
        this.position = position;
    }

    @Override
    public String toString() {
        String reuslt = String.format("TreeNodeval = %d, position = %d, level = %d\n", this.node.val, this.position, this.level);
        return reuslt;
    }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Comparator<State> comparator = new Comparator<State>() {
            @Override
            public int compare(State o1, State o2) {
                if(o1.position == o2.position){
                    if(o1.level == o2.level){
                        return o1.node.val - o2.node.val;
                    }else {
                        return o1.level - o2.level;
                    }
                }else{
                    return o1.position - o2.position;
                }
            }
        };

        Queue<State> FsQueue = new PriorityQueue<State>(comparator);
        Queue<State> queue = new LinkedList<>();
        ((LinkedList<State>) queue).add(new State(root, 1000, 1));

        while(!queue.isEmpty()){
            State tmp = queue.poll();
            FsQueue.add(tmp);
            //System.out.print(tmp.toString());
            if(tmp.node.left != null){
                ((LinkedList<State>) queue).add(new State(tmp.node.left, tmp.position-1, tmp.level+1));
            }
            if(tmp.node.right != null){
                ((LinkedList<State>) queue).add(new State(tmp.node.right, tmp.position+1, tmp.level+1));
            }
        }
        
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        int prePosition = -1;
        
        //System.out.print("\n\n\n");
        
        while(!FsQueue.isEmpty()){
            State state = FsQueue.poll();
            //System.out.print(state.toString());
            if(state.position == prePosition){
                tmp.add(state.node.val);
            }else{
                if(tmp.size() > 0)
                    result.add(tmp);
                tmp = new ArrayList<>();
                tmp.add(state.node.val);
                prePosition = state.position;
            }
        }
        if(tmp.size() > 0)
            result.add(tmp);
        
        return result;

    }
}

```