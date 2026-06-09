### 解题思路
一开始思路就是相乘后保留回去，然后排序，执行用时3ms。

后来用双指针写，另开辟一个空间ans，由于存在负数的情况，所以两个指针一个从头，一个尾进行比较，把较大的倒序保存到ans中。

需要注意的是left = right的情况

### 代码

```java
// class Solution {
//     public int[] sortedSquares(int[] A) {

//         for(int i = 0; i < A.length; i++){
//             A[i] = A[i] * A[i];
//         }

//         Arrays.sort(A);

//         return A;
//     }
// }

class Solution {
    public int[]  sortedSquares(int[] A){

        int len = A.length;

        int left = 0, right = len - 1, k = len - 1;

        int[] ans = new int[len];

        while(left <= right){
            if(Math.abs(A[left]) >= Math.abs(A[right])){
                ans[k] = A[left] * A[left];
                k--;
                left++;
            }else{
                ans[k] = A[right] * A[right];
                k--;
                right--;
            }
        }
        return ans;
    }
}
```