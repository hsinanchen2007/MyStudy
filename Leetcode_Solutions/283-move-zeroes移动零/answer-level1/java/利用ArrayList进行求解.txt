### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        List<Integer> newNumsArr = new ArrayList<>();
        int[] newNums = new int[nums.length];//记录非0元素的下标
        int count = 0;//记录0的个数
        for(int num:nums){
            count = (num == 0)?++count:count;
            if(num != 0){
                newNumsArr.add(num);
            }
        }
        for (int i = count; i > 0; i--) {
            newNumsArr.add(0);
        }
        for (int i = 0;i < nums.length;i++) {
            nums[i] = newNumsArr.get(i);
        }
    }
}
```