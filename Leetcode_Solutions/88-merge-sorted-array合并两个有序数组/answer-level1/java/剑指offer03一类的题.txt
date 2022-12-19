### 解题思路

1.从前往后赋值，移动一个数字多次

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int cur1=m-1;
        int cur2=n-1;
        int k=m+n-1;
        
        while(cur1>-1&&cur2>-1){
           

            if(nums1[cur1]>nums2[cur2]){
                nums1[k]=nums1[cur1];
                
                cur1--;
            }
            else{
                nums1[k]=nums2[cur2];
                cur2--;
            }
           
            k--;
        }
        
         while(cur2>-1){
            nums1[k]=nums2[cur2];
            cur2--;
            k--;
        }



    }
}
```