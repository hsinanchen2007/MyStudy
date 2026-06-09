### 解题思路
利用数组a记录数组nums里元素出现的次数，对次数进行判断即可

### 代码

```java
//用时2ms
class Solution {
    public int findRepeatNumber(int[] nums) {
        int a[] = new int[nums.length];
        for(int i=0; i<nums.length; ++i) {
            ++a[nums[i]];
            if(a[nums[i]]>1) {
                return nums[i];
            }
        }
        return -1;
    }
}

// 这是我最开始的解法，这种解法的思路和上面一样，但是运行起来比上面的用时要短，但是我觉得上面的这种我后来改进的方法最好理解，而且简洁
// 用时1ms
// class Solution {
//     public int findRepeatNumber(int[] nums) {
//         int i, ret=0;
//         int a[] = new int[nums.length];
//         for(i=0; i<nums.length; ++i) {
//             ++a[nums[i]];
//         }
//         for(i=0;i<nums.length;++i) {
//             if(a[i]>1) {
//                 ret = i;
//                 break;
//             }
//         }
//         return ret;
//     }
// }


// 大佬的解法，值得学习
// 用时0ms
// class Solution {
//     public int findRepeatNumber(int[] nums) {
//          int temp;
//         for(int i=0;i<nums.length;i++){
//             while (nums[i]!=i){
//                 if(nums[i]==nums[nums[i]]){
//                     return nums[i];
//                 }
//                 temp=nums[i];
//                 nums[i]=nums[temp];
//                 nums[temp]=temp;
//             }
//         }
//         return -1;
//     }
// }
```