思路：
由于没有规定元素的位置，只需要奇偶元素交换即可，所以采用双指针就行，两指针指向的元素分别有如下情况：
1. nums[i]是奇数，nums[j]是偶数，两元素交换，双指针移动
2. nums[i]是偶数，nums[j]是偶数，指向nums[i]的指针移动
3. nums[i]是奇数，nums[j]是奇数，指向nums[j]的指针移动
4. nums[i]是偶数，nums[j]是奇数，双指针移动

代码：
```
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i=0,j=nums.length-1;
        while(i<j){
            if(nums[i]%2 !=0 && nums[j] %2==0){//nums[i]奇数--nums[j]偶数
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }else if(nums[i]%2 == 0 && nums[j]%2 == 0){//nums[i]偶数--nums[j]偶数
                i++;
            }else if(nums[i]%2 != 0 && nums[j]%2 != 0){//nums[i]奇数--nums[j]奇数
                j--;
            }else{//nums[i]偶数--nums[j]奇数
                i++;
                j--;
            }
            
        }
        return nums;
    }
}
```
