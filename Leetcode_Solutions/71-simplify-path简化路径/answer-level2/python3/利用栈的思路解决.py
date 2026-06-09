LeetCode 71题：
简化Unix路径，参照了别人的思路；

栈顶元素反映了在嵌套的层次关系中，最近的需要匹配的元素。那么对于路径，要解决的就是，怎么算是最近要匹配的。参考示例，可以得出:将.和目录名作为匹配的元素。
第一步：通过/将院有的字符串分割成list;

第二步：遍历list，如果元素不为空的话，则将此元素入栈；为空,表明此时的元素是/,最后再对栈的元素用/拼接即可；
if 遍历的元素 不为空: 入栈

第三步：考虑到最后用/进行join，如果是.的话，join后相当于不动，所以遍历的元素条件不能是.；
if 遍历的元素 不为空 且 不为.: 入栈

第四步：考虑..的情况， 因为最后用了/进行join,所以/..才是出栈的情况:
if 遍历的元素 == '..'：出栈

自己在做时，一直在纠结如何每个条件把/加上去，看了这个题解时，通过'/'.join来一次性解决，而后将..与目录进行配对，很是巧妙，但自己没有想到。

关键点：定义栈顶匹配的元素、以/进行join

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path_lis = path.split('/')
        lis = []
        for char in path_lis:
            if char == '..':
                if stack:
                    stack.pop()
            elif char and char != '.':
                stack.append(char)
        return '/'+'/'.join(stack)
```
