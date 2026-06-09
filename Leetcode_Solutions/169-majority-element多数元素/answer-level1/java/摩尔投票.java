### 解题思路
通过遍历确定留到最后的就是大多数
首先，选取 nums[0] 作为 res_num，由于接下来要用 for each 遍历，所以开始 count = 0
在遍历过程中当此时的 i == res_num， count++,否则 count--,并判断此时count 是否等于 0，等于0时，选取当前的 i 作为 res_num,count 置1
最后的 res_num 就是大多数的数

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int res_num = nums[0];
        int count = 0;
        for (int i : nums) {
            if(res_num == i) {
                count++;
            }else {
                count--;
                if(count == 0){
                    res_num = i;
                    count = 1;
                }
            }
        }
        return res_num;
    }
}
```