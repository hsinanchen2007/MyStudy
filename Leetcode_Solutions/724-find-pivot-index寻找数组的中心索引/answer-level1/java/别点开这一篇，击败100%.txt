### 解题思路
方法二：一开始的思路就是，我从数组的中间，分别计算左边和右边的sum。比较左边、右边的大小，然后大的地方就减少一个元素，小的就增加。
但是这有个问题，就是如果遇到负数，增加元素反而是减小了。
就这样打补丁式的方法最终超过时间限制了。

方法一：先计算数组总值，然后从左开始添加，如果存在中心索引的话，中心索引左右两边的值相等，因此sumLeft * 2 + nums[i] == sum。

### 代码
方法一：
```java
class Solution {
    public int pivotIndex(int[] nums){
        int sum = 0, sumLeft = 0, len = nums.length;

        for(int num:nums) sum += num;

        for(int i = 0; i < len; i++){
            if(sumLeft * 2 + nums[i] == sum){
                return i;
            }
            sumLeft += nums[i];
        }

        return -1;
    }
}

方法二：

// class Solution {
//     public int pivotIndex(int[] nums) {

//         int len = nums.length;

//         if(len == 0) return -1;
//         int start = len / 2;

//         int left = 0, right = 0;
//         for(int i = 0; i < start; i++){
//             left += nums[i];
//         }

//         for(int j = len - 1; j > start; j--){
//             right += nums[j];
//         }

//         if(left > right){
//             while(left > right){
//                 if(nums[start] >= 0){
//                     right += nums[start];
//                     left -= nums[start - 1];
//                     start -= 1;
//                 }else{
//                     left += nums[start];
//                     right -= nums[start + 1];
//                     start += 1;
//                 }  
//             } 
//         }else if(left < right){
//             while(left < right && start < len - 1){
//                 if(nums[start] >= 0){
//                     left += nums[start];
//                     right -= nums[start + 1];
//                     start += 1; 
//                 }else{
//                     right += nums[start];
//                     left -= nums[start - 1];
//                     start -= 1;
//                 }
                
//             }
//         }
//         return left == right ? start : -1;
//     }
// }
```