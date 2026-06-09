### 解题思路
本题使用**双索引指针**一前一后进行比较输出

通过while循环，一次遍历整个数组，当sum == target的时候 将下标+1的位置值放入新的数组new int[]中

否则就移动左右索引指针，如果最后没有找到满足题意的值则返回null即可。
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int l = 0;
        int r = n - 1;
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                return new int[] {l + 1, r + 1};//将满足题意的位置放入新的数组
            }else if(sum > target){
                r--;
            }else{
                l++;
            }
        }
        return null;
    }
}
```