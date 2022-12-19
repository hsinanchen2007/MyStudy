### 解题思路

很简单的想法，从最后一个有效位开始比，把较大的放在 `A` 的预留位的最后一位上。

然后，如果是 B 的长度小于 A，那么我们上一步执行完以后就已经得到了有序数组。

如果 B 长度大于 A，则只需要把 B 中剩余的数字依次填入就好。

### 代码

```python3 []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        i, j = m-1, n-1
        len = m + n-1
        while i >= 0 and j >= 0: 
            if A[i] > B[j]:
                A[len] = A[i]
                len -= 1
                i -= 1
            else:
                A[len] = B[j]
                len -= 1
                j -= 1

        while j >= 0 and len >= 0:
            A[len] = B[j]
            len -= 1
            j -= 1
```

```c []
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
        int len = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j]) {
                A[len--] = A[i--];
            } else {
                A[len--] = B[j--];
            }
        }

        while(j >= 0 && len >= 0) { A[len--] = B[j--]; }

}
```

```rust []
impl Solution {
    pub fn merge(a: &mut Vec<i32>, m: i32, b: &mut Vec<i32>, n: i32) {
        let mut len = (m + n - 1) as usize;
        let mut i = m as usize;
        let mut j = n as usize;
        
        while i > 0 && j > 0{
            if a[i-1] >= b[j-1]{
                a[len] = a[i-1];
                len -= 1;
                i -= 1;
            }else{
                a[len] = b[j-1];
                len -= 1;
                j -= 1;
            }
        }
        while j > 0{
            a[len] = b[j-1];
            len -= 1;
            j -= 1;
        }
    }
}
```