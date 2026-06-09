### 解题思路
1）遍历nums1中的元素，看nums1中的元素是否在nums2中出现过，若出现则保存此元素到结果集，若未出现则跳过
2)保存元素到结果集的过程中，如果元素已经存在于结果集中则不处理
### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) {
            return new int[0];
        }
        int[] result = new int[0];
        int temp;
        int flag =0;
        for (int i = 0; i < nums1.length; i++) {
            temp = nums1[i];
            for (int j = 0; j < nums2.length; j++) {
                if (nums2[j] == temp && !this.assertExisted(result,temp)){
                    result = this.addSize(result,1);
                    result[flag++] = temp;
                    
                }
            }
        }
        return result;
    }

    private int[] addSize(int[] nums , int gap){
        if (gap == 0){
            return nums;
        }
        return Arrays.copyOf(nums,nums.length+1);
    }
    
    private boolean assertExisted(int [] result,int temp){
        if (result.length ==0){
            return false;
        }
        for (int i=0;i<result.length;i++){
            if (result[i] == temp){
                return true;
            }
        }
        return false;
    }


}
时间复杂度：O（n^3)
空间复杂度：O（n)
```
