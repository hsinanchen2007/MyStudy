```java
public class Solution extends Relation {
    public int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            int know = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (!knows(i, j) && knows(j, i)) {
                    know++;
                } else {
                    break;
                }
            }
            if (know == n-1) {
                return i;
            }
        }
        return -1;
    }
}
```