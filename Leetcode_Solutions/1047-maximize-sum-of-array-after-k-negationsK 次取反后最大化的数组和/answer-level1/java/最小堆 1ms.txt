![image.png](https://pic.leetcode-cn.com/77bba1cee6ea762fe0960706eddce4e68b671ffddcab7f1fd14bda997b867e51-image.png)

```
class Solution {
    public  int largestSumAfterKNegations(int[] A, int K) {


       findMin(A);
        A[0] = -A[0];

        if (K>1){
            for (int i = 1; i <K ; i++) {
                adjust(A,0,A.length);
                A[0] = -A[0];
            }
        }

        int sum =0;
        for (int i = 0; i < A.length; i++) {
            sum +=A[i];
        }

        return sum;
    }

    public  void findMin(int[] A){
        for (int i = A.length/2-1; i >=0 ; i--) {
            adjust(A,i,A.length);
        }
    }


    public  void adjust(int[] A,int i,int length){
        int temp = A[i];
        for (int j = 2*i+1; j < length; j = 2*j+1) {
            if (j+1<length && A[j]>A[j+1]){
                j++;
            }

            if (A[j]<temp){
                A[i] = A[j];
                i = j;
            }else {
                break;
            }
            A[i] = temp;
        }
    }
}
```
