自己写的Java解法, 优点是写得绝对简单, 缺点是性能一般。

首先定义两个数组`int[] B `, `int[] C`
B 用来接收 A 中为偶数的项,
C 用来接收 A 中为奇数的项,
第一次循环得到B 和 C 各项的值, 并且记录B的长度`len`。
接着定义一个新的数组`int[] arr`作为返回值，
再次循环, 首先读入数组B, 读入`len`次以后开始读入数组C

代码如下：
```

public class sortArrayByParity_905 {
    public int[] sortArrayByParity(int[] A) {
        // B 用来接收 A 中为偶数的项
        int[] B = new int[A.length];
        int j = 0;

        // C 用来接收 A 中为奇数的项
        int[] C = new int[A.length];
        int k = 0;

        // 第一次循环得到B 和 C 各项的值, 并且记录 B 的长度 len
        for (int i = 0; i < A.length; i++) {
            if (A[i] % 2 == 0) {
                B[j] = A[i];
                j++;
            }

            // 读入 len 次以后开始读入数组C
            else {
                C[k] = A[i];
                k++;
            }
        }
        int len = j;

        // 定义一个新的数组 int[] arr 作为返回值
        int[] arr = new int[A.length];

        // 再次循环
        for (int i = 0; i < A.length; i++) {
            // 首先读入数组B
            if (i < len) {
                arr[i] = B[i];
            }
            else {
                arr[i] = C[i - len];
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        sortArrayByParity_905 sort = new sortArrayByParity_905();
        int[] A = {3,1,2,4};
        int[] arr;
        arr = sort.sortArrayByParity(A);
        System.out.println(arr);

    }
}

```

**执行用时** :2 ms, 在所有 Java 提交中击败了48.31% 的用户
**内存消耗** :40.9 MB, 在所有 Java 提交中击败了26.42%的用户

