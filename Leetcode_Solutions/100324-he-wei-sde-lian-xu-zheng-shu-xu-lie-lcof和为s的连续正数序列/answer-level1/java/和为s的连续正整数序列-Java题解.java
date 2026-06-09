### 解题思路
学习自他人的滑动窗口法
思路：
- 创建双指针i，j都指向1，sum求和。i，j之间就是窗口大小
- 若target大于sum说明数字之和 不够，右指针j需要右移j++直至sum小于target（等于时直接跳出存储结果到list）
- 若此时target小于sum说明数字之和 超出，调整左指针i--直至满足sum=target

### 算法步骤
1. 创建指针、求和变量和list集合（用于存储满足的结果）
2. 当左指针i小于等于target/2时，判断sum和target的大小关系，sum小则右指针往右移动一位，大则左移一位
3. 等于时记录到list集合中，并且让sum减去i，左指针右移，重新下一次寻找
4. list转换为int[][]类型后返回

注意：题目的条件是至少返回两个连续正整数，所以判断循环条件为i <= target/2。假设i > target/2，那么下一位i + 1与i的和必定大于target。“=” 的情况之一例如9，target/2 = 4，存在i+i+1=target，因此列入其中。

时间复杂度：O(target) 指针只向右移动，遍历一遍为target/2次
空间复杂度：O(1) 除了list和目标数组都是常量
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int i = 1;
        int j = 1;
        int sum = 0;
        List<int[]> list = new ArrayList<>();

        while(i <= target/2){
            if(sum < target){
                sum += j;
                j++;
            }else if(sum > target){
                sum -= i;
                i++;
            }else{
                int[] tmp = new int[j-i];
                for(int k = i;k < j;k++){
                    tmp[k - i] = k;
                }
                list.add(tmp);
                sum -= i;
                i++;
            }
            
        }
        return list.toArray(new int[list.size()] []);
    }
}
```