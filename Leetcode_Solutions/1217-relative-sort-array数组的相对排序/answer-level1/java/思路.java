### 解题思路
此处撰写解题思路
我的思路:
    通过原始数组2和原始数组1进行排序排序比较，用原始数组2一=当前的值和原始数组1一个一个的进行比较，如果
相等的话就直接赋值当前顺序的位置上，依次累加，后来发现少了几个没有的值，又去遍历原始数组1和原始数组2，将
没有的那几个值放入到继续存放到新数组中，又为了放进去的时候那些没有的值是排序的，又重新对原始数组1进行了排序ok
最后返回的数组；
### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int arr3[]=new int[arr1.length];
        int k=0;
        boolean flag=false;
        int c[]=new int[arr1.length];
        int p=0;
        int index=0;
        for(int i=0;i<arr1.length-1;i++){
            for(int j=i+1;j<arr1.length;j++){
                if(arr1[i]>arr1[j]){
                    int t=arr1[i];
                    arr1[i]=arr1[j];
                    arr1[j]=t;
                }
            }
        }

        for(int i=0;i<arr2.length;i++){
            for(int j=0;j<arr1.length;j++){

                    if(arr2[i]==arr1[j]){
                        arr3[k]=arr1[j];
                        k++;
                    }
            }
        }

        for(int i=0;i<arr1.length;i++){
            for(int j=0;j<arr2.length;j++){
                if(arr1[i]==arr2[j]){
                    flag=true;
                    break;
                }else{
                    index=i;
                    flag=false;
                }
            }
            if(!flag){
                arr3[k]=arr1[index];
                k++;
            }
        }
        return arr3;
    }
}
```