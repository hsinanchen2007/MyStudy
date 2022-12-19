### 解题思路
![图片.png](https://pic.leetcode-cn.com/75b5b082ba2a0e209c4e44832bfcb14ebe858847954ea2e8c832313e17ba604b-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] consistant = new int[nums1.length];
        int i = 0,j = 0,k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                consistant[k] = nums1[i];
                k++;
                i++;
            }else{
                consistant[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i < m){
            consistant[k] = nums1[i];
            i++;
            k++;
        }
        while(j < n){
            consistant[k] = nums2[j];
            k++;
            j++;
        }
        // for(int l = 0;l < nums1.length;l++){
        //     nums1[l] = consistant[l];
        // }
        System.arraycopy(consistant,0,nums1,0,nums1.length);
    }
}
```