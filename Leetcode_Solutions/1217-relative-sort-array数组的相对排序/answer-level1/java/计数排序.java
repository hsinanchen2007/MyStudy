执行用时 :1 ms, 在所有 Java 提交中击败了98.43%的用户
内存消耗 :36.1 MB, 在所有 Java 提交中击败了100.00%的用户

```
 int max = arr1[0];int min = arr1[0];
        for (int i = 0; i < arr1.length; i++){
            if (arr1[i]>max){
                max = arr1[i];
            }
            if (arr1[i]<min){
                min = arr1[i];
            }
        }
        
        int [] arr1new = new int [max-min+1];
        for (int i = 0; i < arr1.length; i++){
            arr1new[arr1[i]-min]++; 
        }
        
        int [] ans = new int [arr1.length];int p = 0;
        for (int i = 0; i < arr2.length; i++){
            while(arr1new[arr2[i]-min] > 0){
                ans[p++] = arr2[i] ;
                arr1new[arr2[i] - min]--;
            }
        }
        for (int i = 0; i < arr1new.length; i++){
            while (arr1new[i]>0){
                ans[p++] = i + min;
                arr1new[i]--;
            }
        }
        return ans;
    }
}
```
