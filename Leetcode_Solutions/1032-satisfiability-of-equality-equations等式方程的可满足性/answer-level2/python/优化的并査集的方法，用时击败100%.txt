### 解题思路
见代码注释

### 代码

```python
class Solution(object):
    def equationsPossible(self, equations):
        """
        通过并査集判断两个字母是否相等
        相等的话直接放到同一个并査集里面，不相等的话，判断是否位于一个并査集
        :type equations: List[str]
        :rtype: bool
        """
        parents = [chr(i+97) for i in range(26)]  # ord('a') = 97 parents[0]表示'a'的父节点，初始化指向自己'a'
        sizes = [1 for _ in range(26)]  # 每棵树的节点总数

        # def find_parent(char1):
        #     while char1 != parents[ord(char1)-97]:
        #         char1 = parents[ord(char1)-97]
        #     return char1

        # 优化：采用路径压缩的方法：降低并査集所形成的的树的高度
        def find_parent(char1):
            while char1 != parents[ord(char1)-97]:
                parents[ord(char1) - 97] = parents[ord(parents[ord(char1)-97])-97]  # parent(x) = parent(parent(x))
                char1 = parents[ord(char1) - 97]
            return char1

        def is_same_parent(char1, char2):
            char1 = find_parent(char1)
            char2 = find_parent(char2)
            return True if char1 == char2 else False

        # def union(char1, char2):
        #     char1 = find_parent(char1)
        #     char2 = find_parent(char2)
        #     if char1 != char2:
        #         parents[ord(char1)-97] = char2
        #     return

        # 优化：小的树向大的树合并
        def union(char1, char2):
            char1 = find_parent(char1)
            char2 = find_parent(char2)
            if char1 != char2:
                if sizes[ord(char1)-97] > sizes[ord(char2)-97]:
                    parents[ord(char2)-97] = char1
                    sizes[ord(char1)-97] += sizes[ord(char2)-97]
                else:
                    parents[ord(char1) - 97] = char2
                    sizes[ord(char2) - 97] += sizes[ord(char1) - 97]
            return

        for s in equations:
            if s[1] == '=':
                char1 = s[0]
                char2 = s[3]
                union(char1, char2)

        for s in equations:
            if s[1] == '!':
                char1 = s[0]
                char2 = s[3]
                if is_same_parent(char1,char2):
                    return False
        return True

# s = Solution()
# print(s.equationsPossible(["a==b","b!=a"]))
# print(s.equationsPossible(["a==b","b==c","a==c"]))
# print(s.equationsPossible(["a==b","b!=c","c==a"]))
# print(s.equationsPossible(["c==c","b==d","x!=z"]))
```