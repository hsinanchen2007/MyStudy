### 解题思路
思路：
    题意要求：
        1.需要保证数组中有两个数相加等于target
        2.数组中这两个数不能重复使用
        3.target表示为任意一个常数
    思路：
        1.由于本题中主要设计就是两个对象target，数组
        2.定义方法twoSum用来返回符合题意的数组，采用类似于冒泡排序方式进行依此比较
           2.1 if语句用来找出符合运算结果为target的下标，最终返回数组类型数组。
    反思：
        本人由于是第一次力扣做算法题，可能解题不够严谨，算法不够优化，请各位大佬多多指教！

### 代码

```java
//定义类Solution
class Solution {
//定义方法用来接收符合数组
    public int[] twoSum(int[] nums, int target) 
    {
//利用冒泡方法实现两个参数依此比较相加
        for(int i=0;i<nums.length-1;i++)
        {
            for(int j=i+1;j<nums.length;j++)
            {
                if((nums[i]+nums[j])==target)
                {
                    //返回匿名数组
					return new int[]{i,j};
                }
            }
        }
      return nums;
    }
}
```