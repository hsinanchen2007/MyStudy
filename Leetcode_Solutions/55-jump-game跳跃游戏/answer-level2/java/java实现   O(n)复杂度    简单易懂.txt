### 解题思路
如果要达不到尾部，必须要有元素为0，且0之前的元素能够到达的位置不能大于0的位置，比如：1,3,1,1,0,3
从第二个数3开始，最多走3步，刚好到达0的位置，此时就到不了尾部了，如果把3改成4,新数组为：1,4,1,1,0,3
这时候就可以到达了，因为从第2个元素开始走4步，刚好跳过了0
算法思想：从第一个数开始，每经过一个数，就减1，并且和当前的数比较，取大的那个数，如果减到小于0了，说明到不了尾部

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length <= 0){
            return true;
        }
        int elem = nums[0];
        for(int i=1; i<nums.length; i++){
            elem -= 1;
            if(elem < 0){
                return false;
            }
            if(nums[i] >= elem){
                elem = nums[i];
            }
           

        }

        return true;
    }
}
```