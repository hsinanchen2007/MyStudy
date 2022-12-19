![image.png](https://pic.leetcode-cn.com/deed76a9484e4808622703ec554d79a6723ca83ca561a9e500109f7b91c80839-image.png)
```
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = 0;
        int j = A.length - 1;
        while(i <= j){
            int temp;
            if(A[i] % 2 == 1){
                if(A[j] % 2 == 0){
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    i++;
                    j--;
                }else{
                    j--;
                }
            }else{
                i++;
            }
        }
        return A;
    }
}
```



