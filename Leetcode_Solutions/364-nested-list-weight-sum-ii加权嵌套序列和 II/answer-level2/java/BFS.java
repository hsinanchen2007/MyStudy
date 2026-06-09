1、BFS搜索过程中求出每一层的和
2、按层压栈
3、出栈时把每层和乘以权重求总和
```
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int result = 0;
        if(nestedList == null || nestedList.size() == 0){
            return result;
        }
        Queue<NestedInteger> queue = new LinkedList<NestedInteger>();
        Stack<Integer> levelSum = new Stack<Integer>();
        for(int i = 0; i < nestedList.size(); i++){
            queue.offer(nestedList.get(i));
        }
        while(!queue.isEmpty()){
            int size = queue.size();
            int eachLevel = 0;
            for(int i = 0; i < size; i++){
                NestedInteger temp = queue.poll();
                if(temp.isInteger()){
                    eachLevel += temp.getInteger();
                }else{
                    for(NestedInteger one : temp.getList()){
                        queue.offer(one);
                    }
                }
            }
            levelSum.push(eachLevel);
        }
        int n = 1;
        while(!levelSum.isEmpty()){
            result += n * levelSum.pop();
            n++;
        }
        return result;
    }
}
```
