### 解题思路
思路一开始就是注释掉的那部分代码，主要就是找到转折的那个点，在这个点之前需要都递增，点之后都递减，若非就return false;

需要注意的是边界的问题，例如全部递减或者全部递增，以及相等的情况。

这个方法耗时2ms。

方法一：一样是找到转折点，但是都使用while，如果当前的点符合的话，index++，最后判断idnex的大小是否是len-1即可。耗时1ms

### 代码
方法一：

```java
class Solution {
    public boolean validMountainArray(int[] A){
        int index = 0, len = A.length;

        while(index < len - 1 && A[index] < A[index + 1]){
            index++;
        }

        if(index == 0 || index == len - 1){
            return false;
        }

        while(index < len - 1 && A[index] > A[index + 1]){
            index++;
        }

        if(index != len - 1){
            return false;
        }
        
        return true;
    } 
}


// class Solution {
//     public boolean validMountainArray(int[] A) {

//         int len = A.length, mid = 0;
        
//         if(len < 3) 
//             return false;

//         for(int i = 0; i < len - 1; i++){
//             if(A[i] == A[i + 1]){
//                 return false;
//             }else if(A[i] > A[i + 1]){
//                 mid = i + 1;
//                 break;
//             }
//         }

//         if(mid <= 1) return false;

//         for(int j = mid + 1; j < len; j++){
//             if(A[j] >= A[j - 1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// }
```