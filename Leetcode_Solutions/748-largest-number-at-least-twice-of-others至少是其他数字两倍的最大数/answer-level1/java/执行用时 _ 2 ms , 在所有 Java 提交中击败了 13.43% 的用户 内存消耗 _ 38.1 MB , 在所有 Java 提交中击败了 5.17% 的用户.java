### 解题思路
我的解法还是有点瑕疵，如下所示，我们先拿到最大值，这个只要比较即可，然后我们如何拿到这个最大值得索引呢，很容易想到map集合，但是如果i为键，我想由值拿到对应的键即索引比较困难，所以调换位置，由值找键，后面就是走程序了。

### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        int max = 0;
        for(int i = 0;i<nums.length;i++) {
            if(nums[i]>=max) {
                max = nums[i];
            }
            map.put(nums[i],i);
        }
        int j = map.get(max);
        int max1 = max/2;
        for(int i = 0;i<nums.length;i++) {
            if(nums[i]==max) {
                continue;
            }
            if(nums[i]>max1) {
                return -1;
            }
        }
        return j;
    }
}
```