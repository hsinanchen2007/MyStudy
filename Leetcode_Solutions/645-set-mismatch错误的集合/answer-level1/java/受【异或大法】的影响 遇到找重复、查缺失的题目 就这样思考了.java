### 解题思路

1、先排序，然后找重复元素，同时使用异或的思想 查找丢失的元素
2、使用一个变量 j ,帮助建立一个1~n的元素 

例如目标数组[1,2,2,4],先通过数组排序，然后查到重复元素为2，取出2后的新数组为[1,2,4],
循环中j的取值为 1,2,3 。temp初始值为4,则循环中执行的就是 4^1^1^2^2^4^3 = 3 ,即得到丢失值

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        //先排序
        Arrays.sort(nums);
        int n = nums.length;
        int j =1; //定义一个异或的元素 取值为 1 ~ n-1 给目标数组创造一个1 ~ n的重复元素
        int temp=n;//目标数组的元素为1~n 但是循环不会执行到n 先将异或的元素设置为n
        int target=0;
        for (int i = 0; i < n ;i++)
            if(i+1 >= n ? true: (nums[i] != nums[i+1] )){//索引越界的处理
                temp ^= nums[i];//异或 排除了重复元素的新的目标数组
                temp ^= j ;     //j为没有丢失的完整数字列
                j++;
                continue;
            }
            target = nums[i];//找到重复元素时 保存目标值
        }
        //使用异或查找缺失数字
        return new int[]{target,temp};
    }
}
