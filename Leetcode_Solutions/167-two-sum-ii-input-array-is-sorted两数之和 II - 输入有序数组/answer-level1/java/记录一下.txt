### 解题思路
......e.....f......
假设e+f=target 那么在两个指针移动的过程中，肯定会有一个先遇到e或f
若左侧指针先到达e，那么e + pointer_right 的值肯定大于target（有序），此时右侧的指针会持续移动直到到达f，满足条件
另一种情况与之类似
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
         int[] index = new int[2];
        int low = 0,hi = numbers.length - 1;
        while(low < hi){
            if (numbers[low] + numbers[hi] == target) {
                index = new int[]{low + 1, hi + 1};
                return index;
            }
            else if(numbers[low] + numbers[hi] < target) ++low;
            else --hi;
        }
        return index;
    }
}
```