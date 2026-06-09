### 解题思路
既然题目要求找到最长的`不包含重复的`子字符串的长度，一看到不重复，这里可以使用`HashSet`进行处理呢~ 此外，还需要维护两个指针`left`和`right`，它们只能向右走，而不能向左走。

整体思路是：在迭代的时候，每次我都要查看指针`right`所指向的字符是不是在`HashSet`中：

- 如果不在`HashSet`中，那就好办了，我直接将`right`所指向的字符放进`HashSet`即可，然后统计`HashSet`的大小，用`max`记录最大长度，然后`right`后移一位；
- 如果在`HashSet`中，我就将指针`left`所指向的字符在`HashSet`中移除，然后`left`再往右移动。

### 分析
以`pwwkew`为例，初始状态如下所示：
```
  left                               max = 0
   ↓
   p    w    w    k    e    w        HashSet：空
   ↑
  right
```
在上图中，由于指针`right`所指向的字符`p`不在`HashSet`中，所以我们把它放进去，同时`right`往右移动一位，然后再比较`max`和`HashSet.size()`的大小，将最大的那个值赋值给`max`。

由于`max`一开始为`0`，`HashSet`的大小为`1`了，所以此时的`max`就更新为`1`。如下所示：
```
  left                               max = 1
   ↓
   p    w    w    k    e    w        HashSet：p
        ↑
       right
```
在上图中，`right`第一次来到了`w`位置，然而在`HashSet`中，没有`w`这个字符，所以将它放进去，然后`right`右移，更新`max`的值。如下所示：
```
  left                               max = 2
   ↓
   p    w    w    k    e    w        HashSet：p w
             ↑
            right
```
在上图中，`right`第二次来到了`w`位置，**然而在`HashSet`中，`w`这个字符已经存在了，所以我们删除`left`所指向的字符`p`**，然后`left`右移，更新`max`的值。如下所示：
```
       left                          max = 2
        ↓
   p    w    w    k    e    w        HashSet：w
             ↑
            right
```
在上图中，此时我们再看`right`所指向的字符`w`还是存在于`HashSet`中，我们再次删除`left`所指向的字符`w`，然后`left`右移，更新`max`的值。如下所示：
```
            left                     max = 2
             ↓
   p    w    w    k    e    w        HashSet：空
             ↑
            right
```
此时`HashSet`为空了，而`max`一直是全局最大值，这个不要忘记了。此时我们再看`right`所指向的字符在没在`HashSet`中，由于没在`HashSet`中，所以再次将`w`放进`HashSet`，`right`右移，更新`max`的值，如下所示：
```
            left                     max = 2
             ↓
   p    w    w    k    e    w        HashSet：w
                  ↑
                 right
```
一直重复此操作，直到`right`越界为止，我们返回最终的`max`即可。（剩下的步骤自己画一下，别偷懒哈~）

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        int left = 0;
        int right = 0;
        int max = 0;
        HashSet<Character> set = new HashSet<>();
        
        while (right < s.length()) {
            // 如果 right 所指向的字符不在 set 中，则将它加入到 set 中
            // 同时 right 右移，更新 max 的值
            if (!set.contains(s.charAt(right))) {
                set.add(s.charAt(right));
                right++;
                max = Math.max(max, set.size());
            // right 所指向的字符已经在 set 中存在了，
            // 那我就把 left 所指向的字符在 set 中删除，同时 left 右移
            } else {
                set.remove(s.charAt(left));
                left++;
            }
        }
        return max;
    }
}
```

### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)