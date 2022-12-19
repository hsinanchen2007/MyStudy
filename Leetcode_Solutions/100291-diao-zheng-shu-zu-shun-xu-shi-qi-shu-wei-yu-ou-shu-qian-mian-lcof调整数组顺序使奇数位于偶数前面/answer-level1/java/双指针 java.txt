**双指针**
    采用前后两个指针，前面的指针用来找偶数，后面的指针用来找奇数，找到后交换位置
**代码**
```
class Solution {
    public int[] exchange(int[] nums) {
        //双指针，p指向前面找到的偶数，q指向后面找到的奇数，然后交换位置
        int p=0;
        int q=nums.length-1;
        //当pq不重合的适合
        while(p<q){
            //当p处为奇数时，p向后移动
            while(nums[p]%2==1&&p<q){
                p++;
            }
            //当q处为偶数时，q向前移动
            while(nums[q]%2==0&&p<q){
                q--;
            }
            //交换pq
            if(p<q){
                int temp=nums[p];
                nums[p]=nums[q];
                nums[q]=temp;
            }
        }
        return nums;
    }
}
```
