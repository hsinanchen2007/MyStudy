是我哪里没有考虑到吗？双百通过：
```java
public int minArray(int[] numbers) {
    if(numbers == null || numbers.length == 0) {
        return -1;
    }
    int min = numbers[0];
    for (int i = 0; i < numbers.length - 1; i++) {
        // 由于数组是递增的旋转，那么找到的第一个比前一个元素小的即为当前最小值
        if(numbers[i] > numbers[i+1]) {
            min = numbers[i+1];
        }
    }
    return min;
}
```
