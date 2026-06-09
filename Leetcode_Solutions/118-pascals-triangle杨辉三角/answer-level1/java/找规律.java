### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        if (numRows == 0) {
            return new ArrayList<>();
        }
        List<List<Integer>> result = new ArrayList<>();
        int[] lastArray = new int[1];
        lastArray[0] = 1;
        result.add(IntStream.of(lastArray).boxed().collect(Collectors.toList()));
        
        int n = 2;
        while (n <= numRows) {
            int[] array = new int[n];
            int head = 0;
            int tail = array.length - 1;
            array[head++] = 1;
            array[tail--] = 1;
            while(head <= tail) {
                array[head] = lastArray[head - 1] + lastArray[head];
                head++;
            }
            result.add(IntStream.of(array).boxed().collect(Collectors.toList()));  
            lastArray = array;
            n++;
        }
        return result;
    }
}

// 1
// 1 1
// 1 2 1
// 1 3 3 1
```