模仿 copy 库的做法，对每一个要深拷贝的对象 x，如果
- x 是 Node 实例，深拷贝 x 的所有属性。重点是根据 memory 的记录避免循环引用：如果 memory 有 x 的记录说明循环引用了，返回查找到的对象；不然深拷贝后记录 x
- x 是基本类型，返回 x  


```
class Solution:
    def _reconstruct(self, node, memory):
        cloned_node = Node(None, None, None)

        memory[id(node)] = cloned_node

        for key, value in node.__dict__.items():
            key = self.copyRandomList(key, memory)
            value = self.copyRandomList(value, memory)
            setattr(cloned_node, key, value)

        return cloned_node

    def _deepcopy(self, node, memory):
        cloned_node = None

        if isinstance(node, Node):
            cloned_node = self._reconstruct(node, memory)
        else:
            cloned_node = node

        return cloned_node

    def copyRandomList(self, head: 'Node', memory=None) -> 'Node':
        if memory is None:
            memory = {}

        cloned_node = memory.get(id(head))

        if cloned_node is None:
            cloned_node = self._deepcopy(head, memory)

        return cloned_node
```
