```
        nodes = []
        stack = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left

            root = stack.pop()
            nodes.append(root)
            root = root.right

        if len(nodes) == 1:
            nodes[0].left = nodes[0].right = nodes[0]
        elif len(nodes) > 1:
            nodes[0].right = nodes[1]
            nodes[0].left = nodes[-1]
            nodes[-1].right = nodes[0]
            nodes[-1].left = nodes[-2]
        for i in range(1, len(nodes) - 1):
            nodes[i].left = nodes[i - 1]
            nodes[i].right = nodes[i + 1]

        return None if not nodes else nodes[0]
```
