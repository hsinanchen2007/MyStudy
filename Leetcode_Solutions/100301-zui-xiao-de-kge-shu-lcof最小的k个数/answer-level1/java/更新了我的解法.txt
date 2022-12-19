### 解题思路
使用Java的Arrays.sort()方法对数组进行排序，取前k位就可以了，此方法内存消耗较小，执行时间稍快

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
    //     int[] min=new int[k];
    //     int pos=0;
    //     for(int i=0;i<min.length;i++){
    //         int min1=arr[0];
    //         min[i]=arr[0];
    //         for(int j=0;j<arr.length;j++){
    //             if(min1>arr[j]){
    //                 min1=min[i]=arr[j];
    //                 pos=j;
    //             }
    //         }
    //         arr[pos]=10001;
    //     }
    //     return min;    
    //    }
        
        Arrays.sort(arr);
        int[] min=new int[k];
        for(int i=0;i<min.length;i++){
            min[i]=arr[i];
        }
        return min;}


    }
```