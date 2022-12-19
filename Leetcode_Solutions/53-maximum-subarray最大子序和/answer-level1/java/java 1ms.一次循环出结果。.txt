### 解题思路
0(n)实现复杂度，O(1)空间复杂度。
对于循环体内的条件分析：
    sum<0，让sum更新为当前下表元素的值。
    sum>0，做累加。
由于题中没有让输出这个最长的数组子串。只用另一个变量来存储Sum的最大值，最后返回即可。  代码如下 ↓ ↓

### 代码

```java

class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int result = nums[0];
        for(int i=0;i<nums.length;i++){
            if(sum > 0){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            result = Math.max(result,sum);
        }
        return result;
    }
}
```