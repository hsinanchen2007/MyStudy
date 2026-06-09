### 解题思路
根据自己头脑中出现的第一个思路写的（也没有别的思路）
用一个指针k来记录不重复元素的位置，初始为0,
取第一个元素，后面的元素依次跟该元素比较，
    1、遇到不同的元素，k往前移动一位，即指向该不同元素的下标
    2、遇到相同的元素，删除该元素，后面的元素往前移动一个位置，
    同时调整数组访问边界及比较元素的下标值
使用双重循环来完成
思路很容易想到，用代码实现比想象的麻烦些，
比如下标调整之类是在idea中一步步调试出来的
如果不用idea，直接看代码修改，应该是写不出正确的结果。
比如调整j下标值需要考虑到for循环中j++影响之类的，看代码想不到，调试了才知道
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 2) return nums.length;
        int k = 0;//记录不重复元素的位置，所以最后返回个数是K+1
        int len = nums.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if(nums[i] != nums[j]){//遇到不同的数字，k往前移动
                    if (k < len -1 ) {
                        k = k + 1;
                        break;
                    }
                }else{//遇到相同的数字
                    //删除相同的数字，即将被删除元素之后的元素往前移动一个位置
                    int r = j;
                    for (r = j; r < len; r++) {
                        if (r < len - 1) {
                            nums[r] = nums[r + 1];
                        }
                    }
                    //元素移动之后，调整数组访问边界值
                    len = len - 1;
                    if(j >= len) break;
                    //元素前移，注意调整j的下标，跟nums[i]比较的是nums[i+1]                                         //之所以是j=i，是因为for循环的j++会使得j = i + 1
                    j = i;
                }
            }
        }
        return k + 1;
    }    
}
```