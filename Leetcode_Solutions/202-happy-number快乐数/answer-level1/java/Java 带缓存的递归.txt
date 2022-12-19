### 代码

```java
import java.util.HashSet;
class Solution {
    public boolean isHappy(int n) {
        if(n==1)return true;
        HashSet<Integer> set = new HashSet<>();
        return isHappy(n, set);
    }

    private boolean isHappy(int n, HashSet<Integer> set) {
        set.add(n);
        int newN = 0;
        while (n != 0) {
            int rest = n % 10;
            newN += rest * rest;
            n /= 10;
        }
        if (set.contains(newN)) return false;
        else return newN == 1 || isHappy(newN, set);
    }

}
```