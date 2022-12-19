### 解题思路
疯狂调试 还是本地IDE 

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int dio=0,cou=0;
        for(int j=n-1;j>=0;){
            if(m-1-dio<0){
                for(;j>=0;j--){
                    nums1[j]=nums2[j];
                }
            }
            else if((nums2[j]>=nums1[m-1-dio])){
                nums1[m+n-1-cou]=nums2[j];
                j--;
            }
            else{
                nums1[m+n-1-cou]=nums1[m-1-dio];
                dio++;

            }
            cou++;
        }

    }
}
```