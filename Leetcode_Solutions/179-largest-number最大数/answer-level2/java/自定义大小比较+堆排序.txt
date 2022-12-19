```
class Solution {   
    class Node implements Comparable<Node> {
        String value;
        public Node(Integer v) {
            this.value = v.toString();
        }
        
         @Override
        public int compareTo(Node o) {
            String s1 = o.value + this.value;
            String s2 = this.value + o.value;
            for (int i = 0; i < s1.length(); i++) {
                char c1 = s1.charAt(i);
                char c2 = s2.charAt(i);
                if (c1 > c2) return -1;
                else if (c1 < c2) return 1;
            }
            return 0;
        }
    }
    
    private int size = 0;
    private Node[] nodes;
    
    public String largestNumber(int[] nums) {
        this.nodes = new Node[nums.length + 1];
        StringBuffer sb = new StringBuffer();
        
        for (int i = 0; i < nums.length; i++) {
            push(nums[i]);
        }
        
        if (nodes[1].value.equals("0")) return "0";
        
        for (int i = 0; i < nums.length; i++) {
            sb.append(pop().value); 
        }
        
        return sb.toString();
    }
    
    //入堆
    private void push(int v) {
        Node newNode = new Node(v);
        nodes[++size] = newNode;
        upHole(size);
    }
    // 出堆
    private Node pop() {
        if (size < 0) return null;
        
        Node popNode = nodes[1];
        nodes[1] = nodes[size];
        size--;
        downHole(1);
        return popNode;
    }
    
    private void upHole(int hole) {
        int par = hole / 2;
        if (par < 1) return;
        if (nodes[par].compareTo(nodes[hole]) == -1) {
            swap(hole,par);
            upHole(par);
        }
    }
    
    private void downHole(int hole) {
        int child = hole * 2;
        if (child > size) return;
        
        if (child + 1 <= size && nodes[child].compareTo(nodes[child+1]) == -1) child++;
        
        if (nodes[child].compareTo(nodes[hole]) == 1) {
            swap(child, hole);
            downHole(child);
        }
    }
    
    private void swap(int i, int j) {
        Node tmp = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = tmp;
    }
}
```

