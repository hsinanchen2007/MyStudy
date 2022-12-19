### 解题思路
//第一反应就是双层的for循环，肯定要取出其中一个去循环本身的数组。

### 代码

```java
class Solution {
    public static int[] smallerNumbersThanCurrent(int[] nums) {
        int[] newc = new int[nums.length];//结果返回数组
        for(int i = 0 ;i<nums.length;i++){//循环当前数组
            int x = 0;//新数组的值，到时候会++的
            int itemi = nums[i];//当前nums的item
            for(int j = 0 ;j<nums.length;j++){//取出来的值去便利自己
                int itemj = nums[j];//赋值
                if(itemi>itemj){//比较
                    x++;//++
                }
            }
            newc[i] = x;//放入新数组
        }
            return newc;
    }
}
```