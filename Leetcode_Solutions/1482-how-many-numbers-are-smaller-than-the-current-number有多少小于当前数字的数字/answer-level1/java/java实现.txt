### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int [] ret = new int[nums.length];//定义返回的数组
        
        for(int i =0;i<nums.length;i++){//从数组0的位置开始循环
            int f =0;//这是用来计比i下标下的个数
            
            for(int j = 0;j<nums.length;j++){//要对比i位置与j位置谁大谁小。同时注意j!=i
                if(j !=i&& nums[i]>nums[j]){
                    f++;
                }
                }
                ret[i]=f;//内层循环完，计算出比当前i下标小的个数。放在返回的数组的位置
            }
            return ret;
        }

    }

```