### 解题思路
这道题的解题思路主要是图论的建模，每个员工是一个顶点，每个员工与该员工的下属的关系是一条边，边上的权值就是这个员工通知该员工下属所需要的时间，最后使用dfs遍历整张图即可，每遍历到一个没有相邻顶点的节点，就记录一下从根节点到这个节点所消耗的时间，并与原来的值进行取最大值的操作，最后返回这个最大值即可获得这道题目的通过。

### 代码

```java
class Solution {
        private int totalConsumer;

        public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
            if (n == 1)
                return 0;
            HashSet<Integer>[] hashSets = new HashSet[n];
            for (int i = 0; i < manager.length; i++) {
                // 不是总负责人
                if (manager[i] != -1) {
                    if (hashSets[manager[i]] == null)
                        hashSets[manager[i]] = new HashSet();
                    hashSets[manager[i]].add(i);
                }
            }
            dfs(headID, hashSets, informTime, 0);
            return totalConsumer;
        }
        
        private void dfs(int currentId, HashSet<Integer>[] hashSets, int[] informTime, int currentTime) {
            HashSet<Integer> hashSet = hashSets[currentId];
            if (hashSet == null) {
                totalConsumer = Math.max(totalConsumer, currentTime);
                return;
            }
            for (Integer i : hashSet)
                dfs(i, hashSets, informTime, currentTime + informTime[currentId]);
        }
    }
```