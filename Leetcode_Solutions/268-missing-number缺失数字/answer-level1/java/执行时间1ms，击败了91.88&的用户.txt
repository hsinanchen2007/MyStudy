### 解题思路
1，最开始考虑先排序，然后一个for循环，下标和对应的值不符合就直接返回，但是排序的复杂度为n*n，于是放弃；
2，再仔细阅读题目，说的是原数组从0,1,2……n中缺少了一个数字，那就考虑额外新建一个数组，长度为原数组长度+1；
3，遍历原数组，原数组的取值为新数组下标，新数组取值为1，标示值存在
4，遍历新数组，当数组取值为0，说明对应的小标值缺失；

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int[] result = new int[nums.length+1];
        for (int i = 0; i < nums.length; ++i) {
            result[nums[i]] = 1;
        }

        int restult = 0;
        for (int j = 0; j < result.length; ++j) {
            if (result[j] == 0){
                restult = j;
                breeak;
            }
        }
        return restult;
    }
}
```