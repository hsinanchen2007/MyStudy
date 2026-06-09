因为以1为根节点层次编号的满二叉树可以对应到位的表示，所以用位运算的思路即可。

因为每层的顺序在变，所以每次需要对首位外的其它位取反。

举例14=1110b，

先将14右移，变为111b，然后对除第一位外所有位取反变为100b，即它的根节点4，

同理100b，右移变为10b，对除第一位外所有位取反变为11b，即它的根节点3

一直到1结束。
```python
    def pathInZigZagTree(self, label: int) -> List[int]:
        res = []
        while label != 1:
            res.append(label)
            label >>= 1
            # 这里我采用异或实现
            label = label ^(1 << (label.bit_length() - 1)) - 1
        return [1]+res[::-1]
```
