### 解题思路
普通的前缀和，
map中记录所有的被K整取的数字，
如果是负数则要转换成对应的正数，比如K=5, -2，那么就是3.

性能和内存都很差，但是比较好理解。

### 代码

```java
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int sum = 0;
        int count = 0;
        map.put(0,1);

        for (int i =0; i< A.length; i++) {
            sum += A[i];
            int res = sum % K < 0 ? K + (sum % K) : sum % K;
            if (map.containsKey(res)) {
                count += map.get(res);
            }

            if (map.containsKey(res)){
                map.put(res, map.get(res)+1);
            } else {
                map.put(res, 1);
            }
        }
        return count;
    }
}
```