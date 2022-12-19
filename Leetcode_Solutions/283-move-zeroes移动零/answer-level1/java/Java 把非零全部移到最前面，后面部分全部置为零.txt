
![屏幕快照 2020-03-29 下午2.34.48.png](https://pic.leetcode-cn.com/672fe63b1d51ce7e237e37c75cf5a1828b482cb516aa90f67f50bbc70fc541bc-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-29%20%E4%B8%8B%E5%8D%882.34.48.png)

j为边界指针，j的前半部分为非零，后半部分为零。
```
class Solution {
    public void moveZeroes(int[] nums) {
        int j=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){//遇到非零直接往前填
                nums[j++]=nums[i];
            }
        }
        while(j<nums.length){//后面全部是零，直接填
            nums[j++]=0;
        }
    }
}
```
