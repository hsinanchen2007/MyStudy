```
public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] count=new int[1001];
        for(int i:arr1){
            count[i]++;
        }
        int start=0;
        for(int i:arr2){
            while(count[i]>0){
                arr1[start++]=i;
                count[i]--;
            }
        }
        for(int i=0;i<1001;i++){
            while(count[i]>0){
                arr1[start++]=i;
                count[i]--;
            }
        }
        return arr1;
    }
```
计数排序，读下标的顺序按数组2顺序来读