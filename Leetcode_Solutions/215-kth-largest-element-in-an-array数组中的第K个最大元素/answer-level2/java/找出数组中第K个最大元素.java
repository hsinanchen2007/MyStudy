### 解题思路
此处撰写解题思路
1.找到数组的中点下标(privot_index)的值，将小于这个值的数放在左边，大于或等于这个数的值放在右边,即patition过程。
2.比较arr.length-k与privot_index,若arr.length-k大，那么就将privot_index右侧的数进行patition；若相等直接返回arr[privot_index]；若arr.length-l小，就将privot_index左侧的数进行patition.
3.while循环结束条件：1、直接找到break; 2、l=r;
4.注意patition过程只需要处理答案所在的那一侧，另外一侧不需要管。
### 代码

```java
class Solution {
     public static int findKthLargest(int[] arr,int k){
        k=arr.length-k;
        int l=0;
        int r=arr.length-1;
        //int j=0;
        while(l<r){
            int j=patition(arr, l, r);
            if(j==k){
                break;
            }else if(j<k){
                l=j+1;
            }else {
                r=j-1;
            }

        }
        return arr[k];
    }

     public static int patition(int[] arr,int l,int r){
        int less=l-1;
        int pivot_index;
       /* if(r-l>0){
              pivot_index=l+random.nextInt(r-l);//返回一个整型，[0,r-l），左闭右开
        }else{
            pivot_index=l;
        }*/
       pivot_index=(r+l)/2;
        //System.out.println(pivot_index);
        swap(arr, r, pivot_index);
        for(int i=l;i<=r;i++){
            if(arr[i]<arr[r]){
                swap(arr, ++less, i);
            }
        }
        swap(arr, r, less+1);//将最右边的数字换到临界点，临界点左边<临界点，临界点右边=>临界点
        return less+1;
    }

    public static void swap(int[] arr,int i,int j){
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
```