### 解题思路
此处撰写解题思路
1）有向图环路判断，需节点遍历依次构成环 2）某链路一旦访问，立即标记
### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int len = prerequisites.length;
        if(len == 0){
            return true;
        }
        Map<String, Boolean> visited = new HashMap<>();
        Map<Integer, Integer> courseMap = new HashMap<>();

        for (int[] requisity : prerequisites) {
            courseMap.put(requisity[0], requisity[1]);
            visited.put(requisity[0] +"_"+ requisity[1], false);
        }

        while(!allVisited(visited)) {
            for (int[] requisity : prerequisites) {
                int pre = requisity[0];
                int next = requisity[1];
                String visite = pre + "_" + next;
                if (visited.get(visite)) { continue; }
                visited.put(visite, true);
                List<Integer> curVisited = new ArrayList<>();
                curVisited.add(pre);

                Stack<Integer> stack = new Stack<>();
                stack.push(next);
                while (!stack.isEmpty()) {
                    int curNode = stack.pop();
                    if (curVisited.contains(curNode)) { return false; }
                    curVisited.add(curNode);
                    Integer nextNode = courseMap.get(curNode);
                    if (nextNode != null) { 
                        stack.push(nextNode);
                        String inVisite = curNode + "_" + nextNode;
                        visited.put(inVisite, true);
                    }
                }
            }
        }
        return true;
    }

    private boolean allVisited(Map<String, Boolean> visited){
        for (Map.Entry<String, Boolean> stringBooleanEntry : visited.entrySet()) {
            if(!stringBooleanEntry.getValue()){
                return false;
            }
        }
        return true;
    }
}
```