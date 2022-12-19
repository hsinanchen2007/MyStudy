#### 思路：
 - 将路径压入栈中，然后遍历路径；
 - 如果文件名为```..```，则弹出栈顶；
 - 为```.```，则不做任何处理；
 - 为其它情况，则置入栈顶
#### 效率：
> Runtime: 40 ms, faster than 63.22% of Python3 online submissions for Simplify Path.
> Memory Usage: 13.9 MB, less than 14.29% of Python3 online submissions for Simplify Path.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
class Solution:

    def simplifyPath(self, path: str) -> str:

        # 如果无路径，直接返回
        if not path:
            return path

        stack = []

        # 构造路径数组，并排除数组内的空值
        path = [file for file in path.split('/') if file]

        # 遍历路径
        for file in path:
            # 文件名为'.'，不做任何处理
            if file == '.':
                continue
            # 文件名为'..'，栈顶值出栈
            elif file == '..':
                try:
                    stack.pop()
                # 如果栈为空，则不做任何处理
                except IndexError:
                    continue
            # 文件名确定，则将文件名置入栈顶
            else:
                stack.append(file)

        # 按照格式返回结果
        return '/' + '/'.join(stack)
```