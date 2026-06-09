二叉树做多了感觉越来越像链表，链表的快慢指针方法、存为列表/字典后操作再转回链表方法，都能找到应用的影子。
```python
class Codec:
    
    def serialize(self, root):
        stack,rst = root and [(0,root)], {}
        while stack:
            k,i = stack.pop(0)
            val = i.val if i else None
            rst[k] = rst.get(k,[])+[val]
            if i:
                stack.append((k+1,i.left))
                stack.append((k+1,i.right))
        return str(rst)     

        

    def deserialize(self, data):
        data=eval(data)
        if data:data[0]=[TreeNode(data[0][0])]
        k = 1
        while k in data:
            data[k] = [TreeNode(x) if x!=None else None for x in data[k]]
            child = data.get(k)
            for i in range(len(data[k-1])):
                if data[k-1][i]==None:continue
                if child:data[k-1][i].left = child.pop(0)
                if child:data[k-1][i].right = child.pop(0)
            k+=1
        return data[0][0] if data else None
```