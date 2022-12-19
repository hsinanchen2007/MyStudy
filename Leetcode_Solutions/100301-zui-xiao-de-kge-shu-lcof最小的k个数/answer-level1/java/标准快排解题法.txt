### 快速排序解法
针对快排的写法，快排后取前k个值

### 代码

```java
class Solution {
     public int[] getLeastNumbers(int[] arr, int k) {
        if(k==0||arr.length==0){
            return new int[0];
        }
        quickSort(arr, 0, arr.length - 1);
        int[] arr1=new int[k];
        for(int i=0;i<k;i++){
            arr1[i]=arr[i];
        }
        return arr1;
    }

    public static void quickSort(int[] arr,int low,int high){
        if(low>high) return;
        int i=low,j=high,temp=arr[low];

        while(i<j){
            while(temp<=arr[j]&&i<j) j--;
            while(temp>=arr[i]&&i<j) i++;

            if(i<j){
                int temp1=arr[i];
                arr[i]=arr[j];
                arr[j]=temp1;
            }
        }

        arr[low]=arr[i];
        arr[i]=temp;
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
}
```