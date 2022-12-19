### 解题思路
解题思路 见解析

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
      int len = nums.length;                //数组长度
        int max = (nums.length+1)/2;        //超过数组长度一半
        int count =1;                       //计数器
        if(len == 1 ||len == 2){            //长度为1、2的特殊情况
            return nums[0];
        }
       for(int i=0;i<len; i++;){            //遍历数组 i指针
            for(int j=i+1;j<len;j++){       //从i后一个开始遍历数组 j指针
                if(nums[i] == nums[j] ){    //如果相邻两个数相等
                    count++;                //计数器加1
                    if(count == max){       //计数器超过数组长度的一半
                        return nums[i];     //返回此数字
                    }
                }
            }
            count = 1;                      //没有相同的 计数器置为1
        }
        return 0;
    }
}
```