### 解题思路
先依据arr2，遍历arr1,把arr2中没有但arr1中有的元素，放在arr1的尾部
再对尾部进行sort
再遍历arr2的每个元素，锁定arr1中的相同元素，再按顺序插入arr1前部中（交换arr1中的元素实现插入）

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
     if(arr2.length!=0){
        int rare=arr1.length-1;
        for(int i=0;i<=rare;i++){
            if(contains(arr2,arr1[i])==-1){
                int temp=arr1[rare];
                arr1[rare]=arr1[i];
                arr1[i]=temp;
                rare--;
                while((contains(arr2,arr1[i])==-1)&&(rare>=i)){
                    int tp=arr1[rare];
                    arr1[rare]=arr1[i];
                    arr1[i]=tp;
                    rare--;
                }
            }
        }
        Arrays.sort(arr1,rare+1,arr1.length);
        int front=0;
        if(rare==arr1.length-1)  rare=arr1.length-2;
        for(int i=0;i<arr2.length;i++){
            while(search(arr1,front,rare+1,arr2[i])!=-1){
                int loc=search(arr1,front,rare+1,arr2[i]);
                int temp=arr1[front];
                arr1[front]=arr1[loc];
                arr1[loc]=temp;
                front++;
            }
        }


     return arr1;
     }
     else{
         Arrays.sort(arr1);
         return arr1;
     }

    }
   public static int contains(int[] arr,int key){
       int result=-1;
       for(int i=0;i<arr.length;i++){
           if(arr[i]==key){
               result=arr[i];
               break;
           }
       }
       return result;
   } 
   public static int search(int[] arr,int from,int to,int key){
       int index=-1;
       for(int i=from;i<=to;i++){
           if(arr[i]==key){
               index=i;
               break;
           }
       }
       return index;
   } 
   















}
```