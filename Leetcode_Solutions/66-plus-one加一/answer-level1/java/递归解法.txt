```
    public int[] plusOne(int[] digits) {
        return reversePlusOne(digits.length - 1, digits);
    }

    public int[] reversePlusOne(int index, int[] digits) {
        if (index < 0) {
            return digits;
        }
        digits[index]++;
        digits[index] %= 10;
        if (digits[index] != 0) {
            return digits;
        } else if (index == 0) {
            digits = new int[digits.length + 1];
            digits[0] = 1;
            return digits;
        }
        return reversePlusOne(index - 1, digits);
    }
```

最好时间复杂度: O(1), 最坏: O(N), 平均: O(1)
最好空间复杂度: O(1), 最坏: O(N), 平均: O(1)
递归调用涉及线程栈开销，也能用到cpu局部混存进行加载数组
迭代方便利用cpu局部缓存，不涉及递归那样线程栈频繁的压入与弹出
