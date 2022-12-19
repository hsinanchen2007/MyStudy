代码，简介
```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] scheduleCources = new int[numCourses];
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            scheduleCources[prerequisites[i][0]]++;
        }
        for (; ; ) {
            // 找一个 入度 为0的节点。
            int i = 0;
            for (i = 0; i < numCourses; i++) {
                if (!visited[i] && scheduleCources[i] == 0) {
                    break;
                }
            }
            if (i == numCourses) {
                break;
            }
            // update the node
            for (int k = 0; k < prerequisites.length; k++) {
                if (prerequisites[k][1] == i) {
                    scheduleCources[prerequisites[k][0]]--;
                }
            }
            visited[i] = true;
        }
        for (int i = 0; i < scheduleCources.length; i++) {
            if (scheduleCources[i] > 0) {
                return false;
            }
        }
        return true;
    }
}
```
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```