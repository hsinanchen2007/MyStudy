### 解题思路
双指针

返回时创建数组的写法需要注意下，不熟练经常写错。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers==null)return null;
        int i=0,j=numbers.length-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target)return new int[]{i+1,j+1};
            if(sum<target)i++;
            if(sum>target)j--;
        }
        return null;
    }
}
```