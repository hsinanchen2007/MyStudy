# 双指针 JAVA版本 剑指offer解法
```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int small = 1, big = 2;
        int tmpSum = small + big;
        while(small < big && big <= (target+1) / 2) {
            if(tmpSum == target) {
                int[] arr = new int[big - small + 1];
                for(int i=small;i<=big;i++)
                    arr[i-small] = i;
                res.add(arr);
                big++;
                tmpSum += big;
            } else if(tmpSum < target) {
                big++;
                tmpSum += big;
            } else if(tmpSum > target) {
                tmpSum -= small;
                small++;
            }
        }
        return res.toArray(new int[0][]); 
    }
}
```
# 以 target = 15 举例
- 维持：`small` 指向最小的元素, `big` 指向最大的元素
```
{1,2}
{1,2,3}
{1,2,3,4}
{1,2,3,4,5} == 15
强制big++ {1,2,3,4,5,6} = 21 > 15 要删掉最小的 1
{2,3,4,5,6}
{3,4,5,6}
{4,5,6} == 15
强制big++ {4,5,6,7} == 22 > 15 
{5,6,7} 
{6,7} = 13 < 15
{6,7,8} = 21 > 15
{7,8} == 15
{7,8,9} == 24 9 > (15+1)/2 stop.
```
# 为什么big最大到 (target+1)/2
- 以`target = 15`举例, `(15+1)/2 = 8` , ` 7 + 8 = 15` 且 `8 + 9 = 17` , 所以`big`最多取到 `(target+1)/2`
