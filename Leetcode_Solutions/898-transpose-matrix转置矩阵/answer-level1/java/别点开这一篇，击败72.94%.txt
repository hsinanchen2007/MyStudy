### 解题思路
除了两个for循环遍历每一个元素之外

被注释掉的部分，大致根据矩阵的长宽分为三种情况，balabala，最终用时与上面那个一样。

### 代码

```java
class Solution{
    public int[][] transpose(int[][] A){
        int l1 = A.length, l2 = A[0].length;

        int[][] ans = new int[l2][l1];

        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
}



// class Solution {
//     public int[][] transpose(int[][] A) {

//         int l1 = A.length, l2 = A[0].length;

//         int[][] ans = new int[l2][l1];

//         if(l1 == l2){
//             for(int i = 0; i < l1; i++){
//                 for(int j = i; j < l2; j++){
//                     ans[j][i] = A[i][j];
//                     ans[i][j] = A[j][i];
//                 }
//             }
//         }else if(l1 < l2){
//             for(int i = 0; i < l1; i++){
//                 for(int j = i; j < l2; j++){
//                     ans[j][i] = A[i][j];
//                     if(i < l2 && j < l1){
//                         ans[i][j] = A[j][i];
//                     }  
//                 }
//             }
//         }else{
//             for(int i = 0; i < l1; i++){
//                 for(int j = 0; j < l2; j++){
//                     ans[j][i] = A[i][j];
//                     if(i < l2 && j < l1){
//                         ans[i][j] = A[j][i];
//                     }  
//                 }
//             }
//         }
//         return ans;

//     }
// }
```