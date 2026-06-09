
**解法一：**
使用数组来实现栈的作用，模拟栈的出栈入栈操作。size表示栈的大小，size-1就是栈顶的位置了。

注意：用数组来实现栈，虽然存取更快，但多数情况下其实不推荐。特别是数组pushed可能特别大的时候，那作为栈的数组stack也会特别大。但实际上同时存在栈中的元素往往不是特别多，这就存在很大的浪费了。
```
public boolean validateStackSequences(int[] pushed, int[] popped) {
    int[] stack = new int[pushed.length];
    int size = 0;
    for (int i = 0, j = 0; i < pushed.length; i++) {
        stack[size++] = pushed[i];
        while (size != 0 && stack[size - 1] == popped[j]) {
            size--;j++;
        }
    }
    return size == 0;
}
```

**解法二：**
仔细观察解法一，你可以发现，其实stack是多余的。在遍历数组pushed的时候，pushed[i]其实就是stack栈顶的元素，这时候，pushed[i-1]、push[i-2]...这些位置已经是"空闲"出来了，所以完全可以用数组pushed来取代stack的作用。
```
public boolean validateStackSequences(int[] pushed, int[] popped) {
    int size = 0;
    for (int i = 0, j = 0; i < pushed.length; i++) {
        pushed[size++] = pushed[i];
        while (size != 0 && pushed[size - 1] == popped[j]) {
            size--; j++;
        }
    }
    return size == 0;
}
```

