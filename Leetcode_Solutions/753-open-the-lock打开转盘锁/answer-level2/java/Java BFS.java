```
class Solution {
    public int openLock(String[] deadends, String target) {
        if("0000".equals(target)) return 0;
        int targetCode = Integer.parseInt(target);
        //备忘录: 由于题目固定取值范围，可使用数组替代哈希表，提高查询速度
        boolean[] memo = new boolean[10000];
        memo[0] = true;
        for(String d : deadends){
            if("0000".equals(d)) return -1;
            int code = Integer.parseInt(d);
            memo[code] = true;
        }
        //BFS
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(new Node(0, 0));
        int[] bases = new int[]{1, 10, 100, 1000};
        while(!queue.isEmpty()){
            Node node = queue.poll();
            for(int k = 0; k < 4; k++){
                //两种翻转的可能
                int base = bases[k];
                int m = (node.code / base) % 10;
                //-1
                int ncode1 = node.code + (m == 0 ? 9 : -1) * base;
                if(!memo[ncode1]){
                    if(ncode1 == targetCode) return node.val + 1;
                    memo[ncode1] = true;
                    queue.add(new Node(ncode1, node.val + 1));
                }
                //1
                int ncode2 = node.code + (m == 9 ? -9 : 1) * base;
                if(!memo[ncode2]){
                    if(ncode2 == targetCode) return node.val + 1;
                    memo[ncode2] = true;
                    queue.add(new Node(ncode2, node.val + 1));
                }
            }
            
        }
        //不可能解锁
        return -1;
    }
    
    class Node{
        int code;
        int val;
        public Node(int code, int val){
            this.code = code;
            this.val = val;
        }
    }
    
}
```
