![批注 2020-03-14 165648.png](https://pic.leetcode-cn.com/ac5b47bc0c1f562a5590317017bade60194fc92549d801c0a1cf70153f18f208-%E6%89%B9%E6%B3%A8%202020-03-14%20165648.png)

```
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
          int len=nums1.length+nums2.length;
          int flag=len%2==0?2:1;

          int l1l=0,l1r=nums1.length-1;
          int l2l=0,l2r=nums2.length-1;
          int upIndex=-1,downIndex=-1;
          while(l1l<=l1r && l2l<=l2r ){
                
                if(nums1[l1l]<=nums2[l2l] ){
                    l1l++;
                    upIndex=1;
                }
                     
                 else {
                       downIndex=1;
                        l2l++;
                      
                    }
                                
                if(nums1[l1r]<=nums2[l2r]){
                        downIndex=2;
                        l2r--;
                    
                } 
                else {
                       upIndex=2;
                        l1r--;
                        
                    
                }

          }
 double result=0;
  //System.out.printf("%d %d %d %d\n",l1l,l1r,l2l,l2r);
          if(l1l<=l1r){
             
              if(flag==1){
                  result=nums1[(l1l+l1r)/2];
              }else{
                  result=(nums1[(l1l+l1r)/2]+nums1[(l1l+l1r)/2+1])/2.0;
              }
              
           
          }else if(l2l<=l2r){
          if(flag==1){
                  result=nums2[(l2l+l2r)/2];
              }else{//System.out.println("fff");
                  result=(nums2[(l2l+l2r)/2]+nums2[(l2l+l2r)/2+1])/2.0;
              }
          }else{
             //  
                 
                 int first,second;
                 if(upIndex==1){
                  first=nums1[l1r];
                 }else{
                     first=nums1[l1l];
                 }
                 if(downIndex==1){
                  second=nums2[l2r];
                 }else{
                     second=nums2[l2l];
                 }
                 result=(first+second)/2.0;
          }
          
return result;
    }
}
```
