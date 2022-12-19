### 解题思路
此处撰写解题思路
两个指针
一个指向较小的数，一个指向较大的数；
当和较小的时候，i++;
当和较大的时候，j--;
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i=0;
        int j=numbers.length-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target) return new int[]{i+1,j+1};
            else if(sum<target) i++;
            else j--;
        }
        return null;
        
    }
}
```