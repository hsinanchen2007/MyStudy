
执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :38.7 MB, 在所有 java 提交中击败了97.18%的用户
```
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int temp=0;int i=0;int j=A.length-1;
        for(i=0,j=A.length-1;i<j;){
           while(A[i]%2==0&&i<j)  i++;
            while(A[i]%2==1&&i<j){temp=A[i];A[i]=A[j];A[j]=temp;j--;}
        }
            
        
         return A;  
        }     
    }
```