![image.png](https://pic.leetcode-cn.com/37685e635324c2228945232c2caac04afbed962aef0657ffe19cf114d87acde9-image.png)

```
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int i=0;
        for(i=1;i*i<n+1;i++);
        i--;
        return i;
    }
};
```
