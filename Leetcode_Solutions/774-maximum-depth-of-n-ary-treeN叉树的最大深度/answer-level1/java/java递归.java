```
class Solution {
    public int maxDepth(Node root) {
        if(root == null) {
            return 0;
        }else {
            List<Integer> list = new ArrayList<>();
            for(Node c : root.children) {
                int t = maxDepth(c);
                list.add(t);
            } 
            int max = 0;
            if(list.size() > 0)
            max = list.get(0);
            for(Integer i : list) {
                if(max < i) {
                    max = i;
                }
            }
            return max+1;
        }
    }
}
```
