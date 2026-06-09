### 解题思路
此处撰写解题思路

### 代码

```rust []
impl Solution {
    pub fn merge(a: &mut Vec<i32>, m: i32, b: &mut Vec<i32>, n: i32) {
        let mut length = (m + n - 1) as usize;
        let mut i = m as usize;
        let mut j = n as usize;
        
        while i > 0 && j > 0{
            if a[i-1] >= b[j-1]{
                a[length] = a[i-1];
                length -= 1;
                i -= 1;
            }else{
                a[length] = b[j-1];
                length -= 1;
                j -= 1;
            }
        }
        while j > 0{
            a[length] = b[j-1];
            length -= 1;
            j -= 1;
        }
    }
}
```
```Java []
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int length = m+n-1;
        while(m > 0 && n > 0){
            if(A[m-1] >= B[n-1]){
                A[length--] = A[m-1];
                m--;    
            }else{
                A[length--] = B[n-1];
                n--;
            }
        }
        while(n > 0){
            A[length--] = B[n-1];
            n--;
        }
    }
}
```