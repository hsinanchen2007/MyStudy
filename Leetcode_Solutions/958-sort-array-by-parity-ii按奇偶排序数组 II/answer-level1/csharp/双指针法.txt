 
```
public int[] SortArrayByParityII(int[] A) {
        int i=0,j=1;
        while(i<A.Length&&j<A.Length){
            if(A[i]%2!=0&&A[j]%2==0){
                var t=A[i];
                A[i]=A[j];
                A[j]=t;
            }
            if(A[i]%2==0){
                i+=2;
            }
            if(A[j]%2!=0){
                j+=2;
            }
            
        }
        return A;
    }
```
