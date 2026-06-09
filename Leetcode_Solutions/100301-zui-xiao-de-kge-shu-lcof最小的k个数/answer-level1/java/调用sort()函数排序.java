
```
public int[] getLeastNumbers(int[] arr, int k) {

    int[] res = new int[k];

    //调用sort()对数组排序
    Arrays.sort(arr);
        
    for(int i=0;i<k;i++){
        res[i]=arr[i];
    }
    return res;
}
```

