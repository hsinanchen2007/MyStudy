### 解题思路
![image.png](https://pic.leetcode-cn.com/f713dcb113855e89c1ef7a75ba6c5fa33432e90d145ad26f136087433db46f37-image.png)

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; k--){
            if(i < 0)
                nums1[k] = nums2[j--];
            else if(j < 0)
                nums1[k] = nums1[i--];
            else{
                if(nums1[i] > nums2[j])
                    nums1[k] = nums1[i--];
                else
                    nums1[k] = nums2[j--];
            }
            
        }
    }
}
```