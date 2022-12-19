### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        //进行排序，这样重复的就出现在一块区域
        Arrays.sort(nums);
        //用于存储第一次计数
        int first = 1;
        //用于和第一次技术比较
        int second = 0;
        //存储出现次数最多的数
        int max = 0;

        for(int i=0;i<nums.length;i++){
            //当出现次数达到数组长度二分之一时，跳出循环
            if(second > nums.length/2){
                break;
            }
            for(int j = i+1;j<nums.length;j++){
                if(nums[i] == nums[j]){
                    first++;
                }else{
                    i = j - 1;
                    break;
                }
            }
            if(first > second){
                second = first;
                first = 1;
                max = nums[i];
            }
        }
        return max;
    }
}
```