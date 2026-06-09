### 解题思路
此处撰写解题思路
定义两个指针，慢指针i指向当前元素，快指针j指向i后面的元素，
如果当前元素为0，则移动快指针查找非0元素，找到则交换，找不到则退出；
快慢指针同时后移；

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int i=0;
        int j=1;
        int temp = 0;
        int len = nums.length;
        while(j<len){
            if(nums[i] == 0){
                while(j<len && nums[j] == 0){
                    j++;
                }
                if(j<len){
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }else{
                    break;
                }    
            }
            i++;
            j++;
        }
    }
}
```