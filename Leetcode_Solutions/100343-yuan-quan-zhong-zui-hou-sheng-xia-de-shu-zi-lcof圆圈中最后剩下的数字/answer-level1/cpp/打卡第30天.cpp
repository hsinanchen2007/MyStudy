原题在剑指offer上
```
class Solution {
public:
    int lastRemaining(int n, int m) {
        int s = 0;
        for(int i=2;i<=n;i++){
            s = (s+m) % i;
        }
        return s;

    }
};
```
