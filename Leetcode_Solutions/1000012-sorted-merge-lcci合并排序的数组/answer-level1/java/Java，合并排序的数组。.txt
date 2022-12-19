### 解题思路
#### 法一：排序
直接将B放入A后面，然后排序.
时间复杂度`O((m+n)log(m+n))`
空间复杂度`O(1)`

#### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for (int i = 0; i < n; i++) {
            A[m+i] = B[i];
        }
        Arrays.sort(A);
    }
}
```

#### 法二：双指针
两指针分别指向A和B的开头，较小值放入新数组C中。
时间复杂度`O(m+n)`
空间复杂度`O(m+n)`

#### 代码
```java
public static void merge(int[] A, int m, int[] B, int n) {
        List<Integer> temp = new ArrayList<>();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i] <= B[j]) {
                temp.add(A[i]);
                i++;
            } else {
                temp.add(B[j]);
                j++;
            }
        }
        if (i < m) {
            for (int k = i; k < m; k++) {
                temp.add(A[k]);
            }
        }
        if (j < n) {
            for (int k = j; k < n; k++) {
                temp.add(B[k]);
            }
        }

        for (int k = 0; k < m+n; k++) {
            A[k] = temp.get(k);
        }
    }
```

#### 法三：双指针不用额外数组
从后向前比较，大者放入A的尾部。
时间复杂度`O(m+n)`
空间复杂度`O(1)`

#### 代码
```java
public void merge(int[] A, int m, int[] B, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while (i >= 0 && j >= 0) {
            if (A[i] <= B[j]) {
                A[k] = B[j];
                k--;
                j--;
            } else {
                A[k] = A[i];
                k--;
                i--;
            }
        }

        if (j >= 0) {
            for (int l = j; l >= 0; l--) {
                A[l] = B[j];
                j--;
            }
        }
    }
```