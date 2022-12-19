### 解题思路
参考大神双指针，@菜鸟
### 代码

```csharp
// public class Solution {
//     public int[] SortedSquares(int[] A) {
//         var res = new int[A.Length];
//         for(int i = 0;i<A.Length;i++){
//                 res[i] = A[i]*A[i];
//         }
//         Array.Sort(res);
//         return res;
//     }
// }
public class Solution{
        public int[] SortedSquares(int[] A){
                int len = A.Length;
                int[] res = new int[len];
                int left = 0;
                int right = len-1;
                int cur = len-1;
                int r = A[right]*A[right];
                int l = A[left]*A[left];
                        
                while(left<=right){
                        if(r>l){
                                res[cur]=r;
                                right--;

                                r = A[right]*A[right];
                        }else{
                                res[cur]=l;
                                left++;
                                if(left<len)
                                l = A[left]*A[left];
                        }
                        cur--;

                }
                return res;
        }
}
```