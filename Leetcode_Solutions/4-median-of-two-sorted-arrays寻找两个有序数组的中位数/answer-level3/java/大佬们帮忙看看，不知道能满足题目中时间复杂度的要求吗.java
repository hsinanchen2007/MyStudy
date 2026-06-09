### 解题思路
思路就是把这两个数组重新排好序放到一个数组里面

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {


    	int len = nums1.length + nums2.length;
        int[] nums3 = new int[len];
        int n = 0;
        double num=0;
        int m = 0;
        for(int i=0;i<nums1.length;i++){
        	for(int j=m;j<nums2.length;j++){
                if(nums1[i]<nums2[j]){
                    nums3[n] = nums1[i];
                    n++;
                    break;
                }else{
                    nums3[n] = nums2[j];
                    m = j+1;
                    n++;
                }
            }
        	if(m == nums2.length) {
                nums3[n] = nums1[i];
                n++;
        	}
        }

    	for(int j=m;j<nums2.length;j++){
            nums3[n] = nums2[j];
            n++;
        }

        if(nums3.length%2 == 0){
            num = (nums3[(len-1)/2] + nums3[(len+1)/2])/2.0 ;
        }else{
            num = nums3[(len-1)/2];
        }
        return num;
    }
}
```