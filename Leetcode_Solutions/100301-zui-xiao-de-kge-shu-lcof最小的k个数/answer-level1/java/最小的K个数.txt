### 解题思路
此处撰写解题思路
1、使用排序算法，重新排序arr数组
2、arraycopy()方法截取k个数

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
    
            quickSort(arr,0,arr.length-1);

     //   System.out.println(Arrays.toString(arr));

        int[] bs = new int[k];
        System.arraycopy(arr, 0, bs, 0, k);
        return bs;

    }

    public  void quickSort(int a[],int l,int r)
     {   
        if(l>=r)
            return;

         int i = l; int j = r;
         int key = a[l];

         


         while(i<j){

         while(i<j && a[j]>=key)//从右向左找第一个小于key的值
             j--;
         if(i<j){
             a[i] = a[j];
             i++;
         }

         while(i<j && a[i]<key)//从左向右找第一个大于key的值
             i++;

         if(i<j){
             a[j] = a[i];
             j--;
         }
     }
        //i == j
        a[i] = key;
        quickSort(a, l, i-1);//递归调用
        quickSort(a, i+1, r);//递归调用
     }

}
```