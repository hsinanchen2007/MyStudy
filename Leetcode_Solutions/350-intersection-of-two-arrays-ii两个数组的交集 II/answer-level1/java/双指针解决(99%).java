```java
import java.util.Vector;
class Solution {
     public static int[] intersect(int[] nums1,int[] nums2){
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i=0;
        int j=0;
        Vector<Integer> vec=new Vector<>();
        while(i<nums1.length){
            if(j<nums2.length){

                  if(nums1[i]==nums2[j]){
                        vec.add(nums1[i]);
                        i++;
                        j++;
                   }
                  else if(nums1[i]<nums2[j]){
                        i++;
                  }
                  else{
                      j++;
                  }
            }
            else
                i++;
        }
        int[] result=new int[vec.size()];
        for(int k=0;k<vec.size();k++)
            result[k]=vec.get(k);
        return result;
    }
}```
双指针