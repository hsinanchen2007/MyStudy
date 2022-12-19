### 解题思路
遍历数据，构造了一个n数组，判断每个位置上的元素是否超过2个，超过就是有重复的


另一种就是 交换法，交换位置，nums[i] 的值为index，判断index 对应的数值是否跟 i 的数值 一样





### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int n = nums.length;
        int[] nlist = new int[n];
        int res=0;
        for (int num :nums) {
            nlist[num] = nlist[num]+1;

            if (nlist[num]>1) {
                res=num;
                break;
            }
        }
        return res;
    }
}
```