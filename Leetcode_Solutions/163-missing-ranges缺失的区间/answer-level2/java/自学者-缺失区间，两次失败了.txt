这个题目第一次做没思路，自己参考别人写出来相当于背诵了题目，在时隔3个月之后，脑海里依旧空白，随意在此处记录下题解，让大脑理顺一下思维，不要混乱，被左边界，右边界弄混乱了。

#### 解题思路
* 先确定在不考虑边界的情况下输出缺失区域，建立对区域基本的测试用例
* 再考虑下边界lower
* 再考虑上边界upper
*
思考用例和系统设计出现偏差：
```
输入：
[5,50]
14
55
按照正常理解：["14->49","51->55"]
系统提示：
预期结果：["6->49","51->55"]
检查了别人输出结果：
实际输出：["14->4","6->49","51->55"]

```
#### 代码
```java []
//Step1. 思维第一步:不考虑边界输出缺失区域逻辑输出
class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
       // 数组的左边界和lower对比一下， 数组右边界到upper
       // 如果for循环，那么只能是nums数组长度无法计算出所有情况
       List<String> result = new ArrayList<>();
       int left = lower;
       for(int i = 0; i < nums.length - 1; i++) {
          int range = nums[i+1] - nums[i];
          if(range == 0 || range == 1) {
              //没有缺失区间
          } else if (range == 2) {
              //缺失1个元素的区间
              result.add(Integer.toString(nums[i] +1));
          } else {
              //缺失2个元素的区间
              result.add((nums[i] +1) +"->" + (nums[i+1] -1));
          }
          
       }
       return result;
    }
}
```
```java []
Step2. 思维第二步：考虑下边界条件lower

```