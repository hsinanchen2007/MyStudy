### 解题思路
- 从`start`遍历到`destination`作为`d1`，再从`destination`遍历到`start`作为`d2`。
- 本来有认为要判断`start`和`destination`的大小，但后来发现没有必要。仅需要在每次递增index后判断`i >= n`即可。
- O(n)时间复杂度。由于数组情况无法在遍历前判断，很难继续优化。

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int n = distance.length;
        int i = start;

        int d1 = 0;
        while (i != destination) {
            d1 += distance[i];
            i++;
            if (i >= n) {
                i %= n;
            }
        }

        int d2 = 0;
        while (i != start) {
            d2 += distance[i];
            i++;
            if (i >= n) {
                i %= n;
            }
        }

        return Math.min(d1, d2);
    }
}
```