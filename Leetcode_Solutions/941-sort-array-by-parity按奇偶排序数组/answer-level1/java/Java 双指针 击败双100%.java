```
public int[] Num905sortArrayByParity(int[] A) {
        int i=0;
        int j=A.length-1;
        while(i<=j)
        {
            if(A[i]%2==1)
            {
                while(i<=j&&A[j]%2==1)
                {
                    j--;
                }
                if(i<=j)
                {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
            i++;
        }
        return A;
    }
```
