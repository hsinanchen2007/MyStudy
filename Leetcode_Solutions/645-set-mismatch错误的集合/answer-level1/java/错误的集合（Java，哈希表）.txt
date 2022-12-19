### 解题思路
第一步：找出重复的数：利用hash表，遍历数组，将数组中的元素填入哈希表，填入之前先检测表中是否有该元素。如果有，这个元素就是重复的元素。
第二步：找出没有的数，由于数是从1-n,如果没有错误的话可以求出1-n的和（等差数列求和），而错误数列的和-重复的元素+缺少的元素应该等于（1+n)*n/2。根据这个方程，先求出错误数列的和以及重复的元素，然后即可解出缺少的元素。

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum=0,dup=0;
        int len=nums.length;
        Map <Integer,Integer> map= new HashMap<Integer,Integer>();
        for(int i:nums)
        {
            sum=sum+i;
            if(map.containsKey(i))
                dup=i;
            else
                map.put(i,1);
        }
        int ans=(1+len)*len/2-(sum-dup);
        return new int[]{dup,ans};
        
    }
}
```