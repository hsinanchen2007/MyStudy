```
public int[] sortArrayByParity(int[] A) {
        int length = A.length;
        if (length <= 1) return A;//如果数组长度小于等于1，直接返回
        int count = 0;//count的值，表示最前面已经有几个偶数了
        for (int i = 0;i < length;i++) {
            if ((A[i] % 2) == 0) {//如果当前值是偶数，就将当前值移动到count下标的位置上
                int temp = A[i];
                A[i] = A[count];
                A[count++] = temp;
            }
        }
        return A;
    }
```
![image.png](https://pic.leetcode-cn.com/c8ee49a933a5f8489f2e624201c4958c454c5c56f64a1f392447fece9dc04e3f-image.png)

