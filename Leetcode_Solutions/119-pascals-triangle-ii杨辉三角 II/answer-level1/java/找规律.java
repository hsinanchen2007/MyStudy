### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        rowIndex++;
        int[] lastArray = new int[1];
        lastArray[0] = 1;
        
        int n = 2;
        while (n <= rowIndex) {
            int[] array = new int[n];
            int head = 0;
            int tail = array.length - 1;
            array[head++] = 1;
            array[tail--] = 1;
            while(head <= tail) {
                array[head] = lastArray[head - 1] + lastArray[head];
                head++;
            }
            lastArray = array;
            n++;
        }
        return IntStream.of(lastArray).boxed().collect(Collectors.toList());
    }
}
```