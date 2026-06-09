### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (prerequisites == null || prerequisites.length == 0) return true;

        // 构建图
        Node[] graph = new Node[numCourses];
        for (int[] plan : prerequisites) {
            // 头插法
            graph[plan[0]] = new Node(plan[1], graph[plan[0]]);
        }
        // 判断是否存在环
        int[] visited = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            // 未遍历则遍历，如果存在环，则不符合要求
            if(visited[i] != -1 && !isDAG(i, graph, visited)) {
                return false;
            }
            // 遍历完成，以i出发不存在环路，置为访问且无环
            visited[i] = -1;
        }
        return true;
    }

    private boolean isDAG(int start, Node[] graph, int[] visited) {
        // 置为正在遍历
        visited[start] = 1;
        Node temp = graph[start];
        while (temp != null) {
            // 之前已经遍历过，无环
            if (visited[temp.val] == -1) {
                temp = temp.next;
                continue;
            }
            // 存在环路
            if(visited[temp.val] == 1 || !isDAG(temp.val, graph, visited)) return false;
            // 遍历结束，置为已访问且无环
            visited[temp.val] = -1;
            temp = temp.next;
        }
        return true;
    }
}

class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
    }

    Node(int val, Node next) {
        this.val = val;
        this.next = next;
    }
}
```