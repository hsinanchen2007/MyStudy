### 解题思路
奇数条和偶数跳和左边调过来的无关，如果某一个位置可以通过奇数跳到的位置可以到终点，那么这个位置就满足要求。
所以需要记住任意点的位置出发进行奇数条和偶数跳是否可以到终点。
从右边往左边计算，遇到相同的值的时候，因为总是取索引最小的，因此刷新treeMap中value的值为新的索引就好了。
时间复杂度O(N*log(N))
空间复杂度O(N)
### 代码

```java
    class Solution {
        int oddEvenJumps(int[] A) {
            TreeMap<Integer, Integer> treeMap = new TreeMap<>();
            boolean[] oddJump = new boolean[A.length];
            boolean[] evenJump = new boolean[A.length];
            oddJump[A.length - 1] = evenJump[A.length - 1] = true;
            treeMap.put(A[A.length - 1], A.length - 1);
            int ans = 1;
            for (int i = A.length - 2; i >= 0; i--) {
                Integer key = A[i];
                Map.Entry<Integer, Integer> evenEntry = treeMap.floorEntry(key);
                evenJump[i] = evenEntry != null && oddJump[evenEntry.getValue()];
                Map.Entry<Integer, Integer> oddEntry = treeMap.ceilingEntry(key);
                oddJump[i] = oddEntry != null && evenJump[oddEntry.getValue()];
                ans = oddJump[i] ? ans + 1 : ans;
                treeMap.put(key, i);
            }
            return ans;
        }
    }
```