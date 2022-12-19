### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int N) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        if(map.containsKey(N)) {
            return map.get(N);
        }

        int result;
        if(N < 2) {
            return N;
        } else {
            result = fib(N -1) + fib(N - 2);
        }

        map.put(N, result);
        return result;
    }
}
```