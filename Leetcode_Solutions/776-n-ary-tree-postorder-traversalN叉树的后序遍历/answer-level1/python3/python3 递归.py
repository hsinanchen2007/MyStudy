
class Solution:
    def __init__(self) -> None:
        self.ret = []

    def postorder(self, root: 'Node') -> List[int]:
        if root is None:
            return self.ret
        for item in root.children[::-1]:
            self.postorder(item)
        self.ret.append(root.val)

        return self.ret
