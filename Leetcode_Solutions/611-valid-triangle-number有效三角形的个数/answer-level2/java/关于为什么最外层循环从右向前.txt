在注释里~
```
class Solution {
    public int triangleNumber(int[] nums) {
        int cnt = 0;
        if(nums.length < 3) return 0;
        Arrays.sort(nums);//先排序
        //如果最外层循环固定最短边，双指针指向另一条短边和一条长边，在不满足两数之和大于第三边的时候，移动两个指针都可能实现
        //所以最外层循环固定最长边，双指针指向剩下的最长和最短，此时如果不符合条件，只能通过增加短边实现
        for(int i = nums.length-1; i >= 2; i--){//>=2,留出另外两条边
            int j = 0, k = i - 1;
            while(j < k){
                if(nums[j] + nums[k] > nums[i]){
                    cnt += k-j;//无需通过while() continue计数，从j+1到k-1都符合，可以直接通过下标算出固定i和k时，j可取的个数；
                    k--;//移动k指针，选择新的k
                }
                if(nums[j] + nums[k] <= nums[i]){ //固定i和k时，找第一个满足的j
                    j++;
                }
            } 
            
        }
        return cnt;
    }
}
```
