**思路：**

顺序遍历或者倒序遍历都可以。以从后往前的倒序遍历为例，用`fruit`数组表示两个水果种类代号，将`tree[len(tree)-1]`加入到`fruit`中，然后指针从最后一棵树开始，往前遍历寻找另一种不同水果。如果找不到，说明只有一种水果，直接返回`len(tree)`。如果找到了，将第二种水果加入到`fruit`中，用`start`和`stop`数组表示两个水果在区间的起始位置和结束位置，则每扫描一个区间，最大长度为`max(stop)-min(start)`，继续扫描下个区间，这时要判断篮子里保存哪个水果，所以需要比较两个水果的起始位置，保留`start`值较小的那种类型的水果，将另一种水果用当前指针新发现的水果替换，保留水果的`stop`值还要用被替换水果的`start`值更新，即`stop[0] = min(stop[0], start[1] - 1)`。

时间复杂度$O(N)$

空间复杂度$O(1)$

**图解：**

![图解](https://pic.leetcode-cn.com/4f2723ba4652d1e5366b72eadbfae143dcaf67b11aa5ec0752fc07200c41b4a7.gif)

**代码：**

倒序遍历

```python
class Solution:
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        l_tree = len(tree)

        if l_tree <= 2:
            return l_tree

        ans = 2

        l = l_tree - 1
        fruit = [tree[l], tree[l]]
        start = [l, l]
        stop = [l, l]

        # find the other fruit
        i = l
        while i >= 0 and tree[i] == fruit[0]:
            i -= 1
        # only one kind of fruit
        if i < 0:
            return l_tree
        else:
            fruit[1] = tree[i]
            start[0] = i + 1
            start[1] = i
            stop[1] = i

        i -= 1
        while i >= 0:
            while i >= 0:
                if tree[i] == fruit[0]:
                    start[0] = i
                elif tree[i] == fruit[1]:
                    start[1] = i
                else:
                    break
                i -= 1

            ans = max(ans, stop[0] - i)
            if start[0] > start[1]:
                fruit = fruit[::-1]
                start = start[::-1]
                stop = stop[::-1]

            stop[0] = min(stop[0], start[1] - 1)
            fruit[1] = tree[i]
            start[1] = i
            stop[1] = i
        
        ans = max(ans, stop[0] - i)
        return ans
```

顺序遍历

```python
class Solution:
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        ans = 0
        to_end = 1
        start = 0
        found = {tree[0]}
        for i in range(1, len(tree)):
            if tree[i] in found:
                to_end += 1
            elif len(found) < 2:
                found.add(tree[i])
                to_end += 1
            else:
                ans = max(to_end, ans)
                to_end = i - start + 1
                found = {tree[i], tree[i-1]}
            # 这里更新两种水果的分界点
            if tree[i] != tree[i-1]:
                start = i
        return max(to_end, ans)
```