### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i=0,j=A.length-1,t;
        while(i<j){
            if(A[i]%2==1&&A[j]%2==0){//前奇后偶
                t=A[i];
                A[i]=A[j];
                A[j]=t;
                i++;
                j--;
            }
            else if(A[i]%2==1&&A[j]%2==1){//前奇后奇
                j--;
            }
            else if(A[i]%2==0&&A[j]%2==1){//前偶后奇
                i++;
                j--;
            }
            else if(A[i]%2==0&&A[j]%2==0){//前偶后偶
                i++;
            }
        }
        return A;
    }
}
```