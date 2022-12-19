    坑点 其一 去除元素也就是去除相同的

    其二 要第一个开始 
class Solution {  // 坑点其一 排除 其二 
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for(int l = 0;l < nums.length-2;l++){
           if(l == 0 || nums[l] != nums[l-1]){  // 第一个开始的数据可以记录下来
            int r = nums.length-1;
            int m = l + 1;
            while(m < r){
                int n = nums[l] + nums[m] + nums[r];
                if( n < 0 ){ m++;
          }else if(n > 0){     r--;
        }else if(n == 0 ){
    res.add(Arrays.asList(nums[l],nums[m],nums[r]));
    m++; r--;  // 在相等的时候 把两者分别分别加一 从而得到需要的结果
    while(m < r && nums[m] == nums[m-1]){  m++;
         } 
   while(r > m && nums[r] == nums[r+1] ){   r--;
                    }
                }
            }
       }
 }
        return res; 
        }
}