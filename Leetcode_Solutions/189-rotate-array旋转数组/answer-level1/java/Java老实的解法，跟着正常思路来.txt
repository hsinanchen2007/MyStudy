### 解题思路
这个使用O(1)的空间复杂度我一直以为只能使用一个变量，不能创建数组的，结果一开始需要两层循环，便利kn次；正确理解了这个O(1)的限制后，新算法思想如下：
1. 给定数组，给定k值，则每个数字的旋转后位置都是固定的
2. 使用大小为k的数组存放最末尾的k个数nums2[k]
3. 数组中从0-length-k位置的都向后移动k个位置
4. nums2[k]赋值给nums1

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int length = nums.length;
        if(length==0 || length==1) return ;
        k = k%length;
        int[] nums2 = new int[k];
        for(int i=0; i<k; i++){
            nums2[i] = nums[length-k+i];
        }
        for(int i=length-1; i>k-1; i--){
            nums[i] = nums[i-k];
        }
        for(int i=0; i<k; i++){
            nums[i] = nums2[i];
        }
    }
}
```