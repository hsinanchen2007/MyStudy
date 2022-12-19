### 解题思路
刚开始没读懂题，查了一下字典序才明白
本题运算复杂度为排序算法复杂度O(nlogn) + 遍历数组复杂度O(n) = O(nlogn)
1. 数组长度小于2时不需要调整返回原数组即可
2. 两个数的组成只有两种，非最大即最小，交换后返回即可
3. 数组长度为3以上的需要调整数字顺序，有两种情况，最大值和非最大值。
- 最大值只需将其数字从小到大排列即可
- 非最大值需要考虑数字怎么调整，例如12321->13122,12345->12354,457621->461257.
      - 从开始调整位置*index*的特点可以看出：*index* - 1 < *index* 时才进行调整（从尾至首）
      - 调整后*index* - 1位置数值的特点是应该为*index*之后最接近*index* - 1的较大值
      - 即只需将*index*及后面的数字从小到大排列即可。

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        if(nums.length <= 1)    //过滤无效数组
        {
            return;
        }
        if(nums.length == 2)    //两个值组合的数组非最大即最小
        {
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return;
        }
        int index = isMaxOrder(nums);
        if(index == -1) //是否为最大序列
        {
            Arrays.sort(nums);  //返回最小序列
        }
        else
        {
            int best = index;
            for(int i = index + 1; i < nums.length; i++)    //从当前位置向后寻找最优值
            {
                if(nums[i] > nums[index - 1])
                {
                    best = nums[best] < nums[i] ? best : i;
                }
            }
            //将需要调整的位置与其交换
            int temp = nums[best];
            nums[best] = nums[index - 1];
            nums[index - 1] = temp;
            Arrays.sort(nums, index, nums.length);  //从调整过后的值开始将其序列调整为最短序列
        }
    }
    public int isMaxOrder(int []nums)   //查看当前数组是否为最大数组，是则返回 -1
    {
        for(int i = nums.length - 1; i > 0; i--)    //从尾至首寻找非递减位置并返回
        {
            if(nums[i - 1] < nums[i]) 
            {
                return i;
            }
        }
        return -1;
    }
}
```