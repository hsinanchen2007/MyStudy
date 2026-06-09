### 解题思路

对于一个数组，假设F(I)是0-I项的解，则arr[I]和arr[I-1]一定有且只有一项，如果选择arr[I]，则F(I）=F(I-2)+arr[I]，如果选择arr[I-1],
则F(I)=F(I-3)+arr[I-1],
可得递归方程
F(I) = Max(F(I-2)+arr[I],F(I-3)+arr[I-1])，
配合辅助数组减少重复计算
### 代码

```java
class Solution {

    int[] store;

    public int massage(int[] arr) {
        store = new int[arr.length];
        Arrays.fill(store, -1);
        if (arr.length == 0) {
            return 0;
        }
        return calc(arr, arr.length - 1);
    }

    public int calc(int[] arr, int index) {
        if (store[index] != -1) {
            return store[index];
        }
        if (index < 0) {
            return 0;
        } else if (index == 0) {
            return arr[0];
        } else if (index == 1) {
            return Math.max(arr[0], arr[1]);
        } else if (index == 2) {
            return Math.max(arr[0] + arr[2], arr[1]);
        } else if (index == 3) {
            return Math.max(Math.max(arr[0] + arr[2], arr[1] + arr[3]), arr[0] + arr[3]);
        }
        int m2 = calc(arr, index - 2);
        store[index -2] = m2;
        int m3 = calc(arr, index - 3);
        store[index -3 ] = m3;
        return Math.max(m2 + arr[index], m3 + arr[index - 1]);
    }
}

```