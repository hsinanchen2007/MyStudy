数组 A 是 [0, 1, ..., N - 1] 的一种排列，N 是数组 A 的长度。全局倒置指的是 i,j 满足 0 <= i < j < N 并且 A[i] > A[j] ，局部倒置指的是 i 满足 0 <= i < N 并且 A[i] > A[i+1] 。

当数组 A 中全局倒置的数量等于局部倒置的数量时，返回 true 。

 

示例 1:

    输入: A = [1,0,2]
    输出: true
    解释: 有 1 个全局倒置，和 1 个局部倒置。
示例 2:

    输入: A = [1,2,0]
    输出: false
    解释: 有 2 个全局倒置，和 1 个局部倒置。
注意:

A 是 [0, 1, ..., A.length - 1] 的一种排列
A 的长度在 [1, 5000]之间
这个问题的时间限制已经减少了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/global-and-local-inversions


### 解题思路
其实仔细查看就发现，局部倒置就是全局倒置。局部倒置等于 `0 <= i < j < N 并且 A[i] > A[j]` ， 其中`j = i+1` 的全局倒置。

所以问题就变成了判断除了局部倒置，数据中是否还有其他的全局倒置，如果有则返回False。这里我们可以简单理解为查找当前索引`i`中，A[i+2:]是否有小于A[i]的数，如果有，则返回False.

所以我们要知道从每个index开始，到数组结尾中最小值。具体做法见代码

##### Python
```python
class Solution(object):
    def isIdealPermutation(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        length_A = len(A)
        min_lst = [0 for i in range(length_A)]
        min_lst[-1] = A[-1] 
        for i in range(length_A-2, -1, -1):
            min_lst[i] = min(min_lst[i+1], A[i]) # 这里是在查找从index，到数据结尾的最小值。
        for i in range(length_A-2):
            if A[i] > min_lst[i+2]: # 说明在i的后面，有一个j,使 A[i] > A[j].
                return False
        return True
```


##### Java
```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int length_A = A.length;
        int[] min_lst = new int[length_A];
        min_lst[length_A-1] = A[length_A-1];
        for(int i=length_A-2;i>=0;i--){
            min_lst[i] = Math.min(min_lst[i+1], A[i]) ;    
        }
        for(int i=0;i<length_A-2;i++){
            if(A[i] > min_lst[i+2])
                return false;
        }
        return true;
    }
}
```