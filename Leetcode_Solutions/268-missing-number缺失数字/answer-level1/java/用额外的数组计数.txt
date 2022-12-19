### 解题思路
    根据题意 给定的范围是0-n 恰好 数组的下标也是从0开始的
    我们可以申请一个额外的数组空间来进行计数 申请空间大小nums.length+1
    第一次遍历nums数组 
    如 nums[0]的值位3  对应的我们把arr[3]这个位置的值 +1  arr[0,0,0,1]
       nums[1]的值位0  对应的我们把arr[0]这个位置的值 +1  arr[1,0,0,1]
       nums[2]的值位1  对应的我们把arr[1]这个位置的值 +1  arr[1,1,0,1]
    最后遍历arr数组
    只要判断arr[i]==0 就可以判定i就是缺失的位
    退出循环

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
            
        int ans=0;
        
        int arr[]=new int[nums.length+1];
        //按位填充 因为数组的下标是天然有序的 
        for (int i = 0; i <nums.length ; i++) {
            //对应的arr[nums[i]]这个位置+1代表有这个数 
            arr[nums[i]]++;
        }
        //最后扫描一遍arr数组 只要arr[i]元素为0就代表第i位缺失 
        for (int i = 0; i <arr.length ; i++) {
            if (arr[i]==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
}
![图片.png](https://pic.leetcode-cn.com/aa1f35ab72093457505cb66e33bf65c5db645f91ec2acd4de27091bee3e7dcbd-%E5%9B%BE%E7%89%87.png)
