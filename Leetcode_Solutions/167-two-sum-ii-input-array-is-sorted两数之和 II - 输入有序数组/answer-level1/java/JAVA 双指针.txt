### 解题思路
这道题采用双指针做法，已知题目数组是有顺序的，left初始化0，right初始化numbers.length-1;
当left<right符合要求，否则数组中没有两个元素想加等于target,返回null,如果相加之和小于则left向右移一个，否则right想左移一个。直到符合要求存入数组two中返回。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers==null) return null;
        int[] two = new int[2];
        int left = 0;
        int right = numbers.length - 1;
        while(left < right){
            int sum = numbers[left]+numbers[right];
            if(sum == target){
                two[0] = left + 1;
                two[1] = right + 1;
                return two;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        return null;
    }
}
```