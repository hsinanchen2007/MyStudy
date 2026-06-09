### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 //两个数交换
        void swap(int[] a,int i,int j){
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
        }
//冒泡排序
    public int[] getLeastNumbers(int[] arr, int k) {
    for(int s =0;s<arr.length;s++){
        for(int n=0;n<(arr.length-s-1);n++){
                    if(arr[n]>arr[n+1]){
                        swap(arr,n,n+1);
                    }

                }
    }
    int[] res = new int[k];
    if(k>=arr.length){
      return arr;
    }else{
        for(int i=0;i<k;i++){
            res[i]=arr[i];
        }
        return res;
    }

       
    }
}
```