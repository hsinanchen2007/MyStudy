使用桶排序来处理：
```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] bucket=new int[1001];
        for (int item:arr1)
            ++bucket[item];
        int p1=0;
        for (int item:arr2){
            while (bucket[item]!=0){
                arr1[p1++]=item;
                --bucket[item];
            }
        }
        //再次遍历桶，将没出现在arr2中的元素升序放到arr1中
        for (int i=0;i<bucket.length;++i){
            if (bucket[i]!=0){
                while (bucket[i]!=0){
                    arr1[p1++]=i;
                    --bucket[i];
                }
            }
        }
        return arr1;
    }
}
```
