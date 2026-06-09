### 解题思路
还是拓扑排序。新建
利用java8 stream减少代码行数。

js应该可以更少代码。
### 代码

```java
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        final int[] pres = new int[numCourses];
        final List<Integer>[] nexts = new List[numCourses];
        for (int[] p : prerequisites) {
            pres[p[1]]++;
            nexts[p[0]] = nexts[p[0]] == null ? new ArrayList<>() : nexts[p[0]];
            nexts[p[0]].add(p[1]);
        }
        Queue<Integer> heads = IntStream.range(0, numCourses).filter(i -> nexts[i] != null && pres[i] == 0).boxed()
                .collect(Collectors.toCollection(LinkedList::new));
        while (heads.size() > 0) {
            final Integer head = heads.poll();
            Optional.ofNullable(nexts[head]).ifPresent(l -> l.stream().filter(n -> (--pres[n]) == 0).forEach(heads::offer));
            nexts[head] = null;
        }
        return Arrays.stream(nexts).noneMatch(Objects::nonNull);
    }
}
```