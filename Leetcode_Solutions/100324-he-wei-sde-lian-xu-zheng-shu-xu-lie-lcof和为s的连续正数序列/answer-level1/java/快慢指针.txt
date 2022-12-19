### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(n)
其中 n 为 target 的大小

### 解题思路
采用快慢指针的思路，检查它们之间所有整数和 sum 的大小与 target 的关系
若 sum > target，则删除一个较小的值，即慢指针 + 1
若 sum < target，则增加一个较大的值，即快指针 + 1

### 代码

```java
class Solution {

    private int capacity = 10;

    private int[][] ans = new int[capacity][];

    public int[][] findContinuousSequence(int target) {

        int small = 1, big = 2;
        int sum;

        int t = 0, p = 0;
        
        // 其实取到 target / 2 就可以了
        while (small < big && small <= target / 2) {
            sum = ((small + big) * (big - small + 1)) / 2;
            if (sum < target) {
                big++;
            }
            else if (sum > target) {
                small++;
            }
            else {
                
                int[] subAns = new int[big - small + 1];

                for (int i = small; i <= big; i++) {
                    subAns[t++] = i;
                }

                t = 0;
                ans[p++] = subAns;

                if (p == capacity) {
                    enlargeCapacity();
                }

                small++;
            }
        }

        changeCapacity(p);

        return ans;
    }

    /**
     * 扩容
     */
    private void enlargeCapacity() {
        capacity += 10;
        ans = Arrays.copyOf(ans, capacity);
    }

    /**
     * 删除数组多余空间
     */
    private void changeCapacity(int retCapacity) {
        ans = Arrays.copyOf(ans, retCapacity);
    }
}
```