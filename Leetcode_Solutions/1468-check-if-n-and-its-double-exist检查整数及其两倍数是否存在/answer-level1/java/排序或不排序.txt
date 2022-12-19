- 先排序，第二遍解决负数问题
```java
public boolean checkIfExist(int[] arr) {
    Arrays.sort(arr); // 负数...0...0...正数
    Set<Integer> set = new HashSet<>();
    for (int value : arr) {
        if (value <= 0) continue; // 只对非负数
        if (set.contains(value)) return true;
        set.add(value * 2);
    }
    set.clear();
    for (int i = arr.length - 1; i >= 0; i--) {
        if (arr[i] > 0) continue; // 只对负数
        if (set.contains(arr[i])) return true;
        set.add(arr[i] * 2);
    }
    return false;
}
```
- 不排序，直接Set
```java
public boolean checkIfExist(int[] arr) {
    Set<Integer> set = new HashSet<>();
    for (int value : arr) {
        if (set.contains(value)) return true;
        set.add(value * 2);
        if ((value % 2) == 0) set.add(value / 2); // 能整除才放入
    }
    return false;
}
```

