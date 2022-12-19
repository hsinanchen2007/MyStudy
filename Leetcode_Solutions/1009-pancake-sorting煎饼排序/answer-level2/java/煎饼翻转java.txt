### 解题思路
找到当前未排序部分最大值的位置，然后以该位置为终点翻转将最大值放提到第一个，然后再以未排序的长度翻转，将该值排序。
若该值已在第一个则不需要提到第一个直接翻转。
若未排序部分只剩当前值，则结束排序。

### 代码

```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {

        int length = A.length;

        List<Integer> list = new ArrayList<Integer>();

        for(int i =length-1;i>=0;i--){

           int max = getPosition(A,i+1);

            if(max!=i){

                if(max!=0){
                reverst(A,max);
                list.add(max+1);
                }
                reverst(A, i);
                list.add(i+1);
            }else if(max==0){

                return list;

            }

        }

        return list;
    }

     private void reverst(int[] A,int target){

      for(int i=0;i<=target/2;i++){

          int temp = A[i];
          A[i] = A[target-i];
          A[target-i] = temp;

      }
    
    }


     private int getPosition(int[] A,int index){

//因为数组A[i]是[1, 2, ..., A.length] 的排列      

        for(int i = 0;;i++){

            if(A[i]==index){
             
                return i;
            }
        }
    }

   
}
```