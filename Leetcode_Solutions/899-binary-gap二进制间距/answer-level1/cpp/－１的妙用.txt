
![image.png](https://pic.leetcode-cn.com/a034de632d258d44ff541a33ce1560bdfa1cd7432489f0d08726b8f04f6ca1f5-image.png)

```
class Solution {
public:
    int binaryGap(int N) {
        int max_distance = 0, distance = -1;
        int last;
        while (N) {
            last = N % 2;
            N >>= 1;
            if (last == 0 && distance != -1) {
                distance++;
            }
            else if (last == 1) {
                distance++;
                max_distance = max(max_distance, distance);
                distance = 0;
            }
        }
        return max_distance;
    }
};
```
