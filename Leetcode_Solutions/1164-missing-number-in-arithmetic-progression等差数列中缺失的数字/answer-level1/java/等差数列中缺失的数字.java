### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] arr) {
        //由于删除的不是第一个，也不是最后一个，因此可以计算出等差数列的和
        //用等差数列的和减去arr数组中的所有元素，剩下的就是缺失的元素
        int sum=(arr[0]+(arr[arr.length-1]))*(arr.length+1)/2;
        for(int i:arr)
            sum-=i;
        return sum;
    }
}
```