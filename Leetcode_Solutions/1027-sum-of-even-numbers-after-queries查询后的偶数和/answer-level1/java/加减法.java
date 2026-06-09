### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
         int arr[] = new int[queries.length];
         int s = 0;
         for(int x:A){
             if((x&1) == 0){
                 s+=x;   //先求偶数和
             }
         }        
         for(int i = 0;i<queries.length;i++){
                int v1 = queries[i][0];
                int v2 = queries[i][1];
                if((A[v2]&1) == 0){   //如果当前是偶数 先减去
                    s-=A[v2];
                }
                  A[v2] = A[v2]+v1;
                   if((A[v2]&1) == 0){  //加上以后还是偶数 在加上
                       s+=A[v2];
                   }

               
           
             arr[i] = s;
        }
        return arr;
        
    }

   
}
```