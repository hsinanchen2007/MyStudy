### 解题思路
这道题挺好的，可以用很简单的思路来解决问题，但是也能让你花时间去想优化的方法。

最初的想法是：分别拎出奇数和偶数，然后再根据对位的奇数偶数填进去。

改进版：想要看看能不能用一个for循环解决，也就是在分清奇数偶数的时候，直接把数字填进去。

双指针版：官方版。先看偶数的位置上有没有奇数，有的话从奇数位置上找一个偶数，两个换位置。要维护两个指针，一个从0开始，一个从1开始。

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A){

        int odd = 1;
        for(int i = 0; i < A.length; i += 2){
            if(A[i] % 2 == 1){
                while(A[odd] % 2 == 1){
                    odd += 2;
                }

                int temp = A[i];
                A[i] = A[odd];
                A[odd] = temp;
            }
        }
        return A;
    }
}


// class Solution{
//     public int[] sortArrayByParityII(int[] A){

//         int len = A.length;
//         int[] ans = new int[len];

//         int even = 0, odd = 1;

//         for(int i = 0; i < len; i++){
//             if(A[i] % 2 == 0){
//                 ans[even] = A[i];
//                 even += 2;
//             }else{
//                 ans[odd] = A[i];
//                 odd += 2;
//             }
//         }
//         return ans;
//     }
// }


// class Solution {
//     public int[] sortArrayByParityII(int[] A) {
//         int len = A.length;

//         int[] even = new int[len / 2];
//         int[] odd = new int[len / 2];

//         int indexE = 0, indexO = 0;

//         for(int i = 0; i < len; i++){
//             if(A[i] % 2 == 0){
//                 even[indexE++] = A[i];
//             }else{
//                 odd[indexO++] = A[i];
//             }
//         }

//         indexE = 0;
//         indexO = 0;
//         for(int j = 0; j < len; j += 2){
//             A[j] = even[indexE++];
//             A[j + 1] = odd[indexO++];
//         }
//         return A;
//     }
// }
```