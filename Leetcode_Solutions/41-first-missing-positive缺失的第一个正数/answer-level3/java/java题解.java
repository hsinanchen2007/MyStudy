# 思路
将数组中的数字放到对应的下标上 比如:{1,2,3,4,5,6},那么缺失的正整数必然是`nums.length+1`.
**对于负数的处理**
那么数组中有负数怎么办?
对于负数我们不进行处理 因为只要把所有正整数放到正确的位置上,那么根据`nums[i] != i+1` 就已经可以知道答案了,没必要去思考负数的处理过程.拿题目中给的例子{3,4,-1,1}举例,我们换完位置之后大概是{1,4,3,-1} 那么 nums[1] != 1+1(`nums[i] != i+1`) 时返回i+1 为2.
代码如下所示:
```
  public static int firstMissingPositive(int[] nums) {
    int length = nums.length;
    if (length == 0) {
      return 1;
    }
    for (int i = 0; i < length; i++) {
      while (nums[i] > 0 && nums[i] < length && nums[i] != nums[nums[i] - 1]) {
        int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    for (int i = 0; i < length; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    //说明位置全都正确 那么长度+1
    return length + 1;
  }
```
结果图:
![image.png](https://pic.leetcode-cn.com/8096d8a1aaf32ae8bc17eae682334f478d682f3f3a1fa484f063a84ad7209b25-image.png)

