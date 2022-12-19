### 解题思路

思路1：
1、一定要考虑重复数据带来的问题（例子不全）
2、边界问题：数组最小值大于target 和数组最大值大于等于 target 都返回数组第一个字符
    注意：这里为什么不考虑数组最小值等于的情况，因为二分法中包含了
3、二分法
3.1、判断大于小于，常规处理，快速定位
3.2、等于时：当前字符和后一个字符不重复，直接返回后一个
3.2.1、当前字符和后一个字符重复时：
3.2.1.1、当前字符和数组最后一个字符相等时，直接返回数组第一个字符（题目要求）
3.2.1.2、当前字符不等于最后一个字符：low指针像右位移，继续查找，直到等于的前后字符不重复时返回

思路2：
1考虑太复杂：
target >= letters[mid] 时：说明范围在letters[mid+1] ~ letters[high] 之间，最后low=high，返回low的值即可。
记录:
一开始以为是一道简单的题，以为不调试就能写出来，结果还是让人尴尬了。
佩服那些手写代码不报错的大牛！


### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int low = 0;
        int high = letters.length -1;
        int mid;
        //考虑边界问题
        if(letters[high] <= target ||letters[low] > target){
            return letters[low];
        }
        while (low < high){
            mid = low + ((high-low)>>1);
            if(target < letters[mid]){
                high = mid;
            }else {
                low = mid +1;
            }
        }
        return letters[low];
    }
}
```