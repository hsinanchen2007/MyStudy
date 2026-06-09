简单易懂
```
class Solution {

    private int depth = 0;

    public int depthSumInverse(List<NestedInteger> nestedList) {
        Deque<List<NestedInteger>> queue = new ArrayDeque<>();
        queue.add(nestedList);
        while(!queue.isEmpty()){
            int size = queue.size();
            depth++;
            while(size-- > 0){
                for(NestedInteger num:queue.poll()){
                    if(!num.isInteger()){
                        queue.add(num.getList());
                    }
                }
            }
        }
        return depthSumInverse(nestedList, depth);
    }

    private int depthSumInverse(List<NestedInteger> nestedList, int level) {
        int sum = 0;
        for(NestedInteger num: nestedList){
            if(num.isInteger()){
                sum += num.getInteger() * level;
            } else {
                sum += depthSumInverse(num.getList(), level - 1);
            }
        }
        return sum;
    }
}
```
