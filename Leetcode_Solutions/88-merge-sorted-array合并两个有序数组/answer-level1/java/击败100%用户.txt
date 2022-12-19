### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] mergeArray = new int[m+n];
        int start1 = 0;
        int start2 = 0;
        int index = 0;

        while(start1 < m || start2 < n){
            // start1走到尽头
            if(start1 == m){
                while(start2 < n){
                    mergeArray[index] = nums2[start2];
                    index++;
                    start2++;
                }
                break;
            }
            // start2走到尽头
            if(start2 == n){
                 while(start1 < m){
                    mergeArray[index] = nums1[start1];
                    index++;
                    start1++;
                }
                break;
            }
            // 
            if(nums1[start1] <= nums2[start2]){
                mergeArray[index] = nums1[start1];
                index++;
                start1++;
            }
            else{
                mergeArray[index] = nums2[start2];
                index++;
                start2++;
            }           
        }
        for(int i = 0; i < m+n; i++){
            nums1[i] = mergeArray[i];
        }
        return;       
    }
}
```