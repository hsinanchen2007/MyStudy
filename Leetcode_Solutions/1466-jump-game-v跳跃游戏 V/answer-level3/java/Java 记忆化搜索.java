
```
private Integer[] cache=null;

public int maxJumps(int[] arr, int d) {
    cache=new Integer[arr.length];
    int res=0;
    for (int i=0;i<arr.length;i++) {
        res=Math.max(jump(arr,d,i),res);
    }
    return res+1;
}

public int jump(int[] arr,int d,int index){ 
    if (cache[index]!=null) {
        return cache[index];
    }
    int res=0;
    //挨个跳,有一个跳不到,后面所有的就都跳不到了
    for (int i=index-1;i>=Math.max(index-d,0) && arr[index]>arr[i];i--) {
        res=Math.max(jump(arr,d,i)+1,res);
    }
    for (int i=index+1;i<=Math.min(index+d,arr.length-1) && arr[index]>arr[i];i++) {
        res=Math.max(jump(arr,d,i)+1,res);
    }
    return cache[index]=res;
}
```
