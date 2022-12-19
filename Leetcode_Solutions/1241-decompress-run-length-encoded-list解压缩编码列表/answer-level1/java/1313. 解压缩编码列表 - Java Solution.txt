### 解题思路
题目难点在于如何确定返回数组的长度，为了解决这一问题，可以分步求解：
1. 根据题目表述，提取`nums`数组下标为奇数的数据相加得到返回数组的长度；
2. 求得返回数组的长度后，依次将`i`个`nums[i+1]`填充到返回数组，即可求得答案。
### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int resultLength=0;
        int i=0;
        while(i<nums.length){
            resultLength+=nums[i];
            i+=2;
        }

        i=0;
        int index=0;
        int[] result=new int[resultLength];
        while(i<nums.length){
            for(int j=0;j<nums[i];j++){
                result[index]=nums[i+1];
                index++;
            }
            i+=2;
        }
        return result;
    }
}
```
### 复杂度分析
- 时间复杂度：$O(n)$（存疑，暂定）
- 空间复杂度：$O(n)$
