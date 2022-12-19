### 解题思路
先组成一个新的数组，然后快速排序，取中位数！
快速算法排序还是掌握的不太好，加油吧！

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
         int lengthNums= nums1.length +nums2.length ;
         int[] totalNums = new int[lengthNums];
        

         for(int i = 0;i<nums1.length;i++){
              totalNums[i] = nums1[i];
         }
         for(int j =nums1.length,i=0 ;j<lengthNums;j++,i++){
              totalNums[j] = nums2[i];
         }
         
          quickQuene(0,lengthNums-1,totalNums);
             
             if(lengthNums%2 ==0) {
                 double result = totalNums[totalNums.length/2]+totalNums[totalNums.length/2 -1];

                 return  result/2;
             }else{
                    return totalNums[(lengthNums-1)/2];
             }

        //  return 0;
    }

      public  void quickQuene(int first,int last,int[] tempNums){
          int i,j;
          int temp = 0;
          if(first>last)
            return;
        
          int init = tempNums[first];
        
        i=first;j=last;
         while(i<j){
             while(tempNums[j]>=init &&i<j){
                  j--;
            }
            while(tempNums[i]<=init &&i<j){
                 i++;
            }
          
            if(i<j){
                
                temp =tempNums[j];
                tempNums[j] = tempNums[i];
                tempNums[i] = temp;
                }
         }
            
            if(i==j){
                tempNums[first] = tempNums[i];
                
                // temp =tempNums[i];
                tempNums[i] = init;
                // init = temp;
                }
         
          quickQuene(first,i-1,tempNums);
          quickQuene(i+1,last,tempNums);
      }

}
```