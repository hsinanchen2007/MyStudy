## 正常二叉树寻路
如果是正常编号的二叉树，则只需每次【1.加入数组】【2.整除2】如此重复即可

## “之”字寻路
与其按照 “之” 字形进行寻路，不如看在正常编号的二叉树中，“之” 字形是怎样的路径
自己在纸上画一下不难发现，在正常二叉树上按“之” 字形寻路就是每次跳到该层对称的子树上
于是则寻路可以简化为【1.加入数组】【2.计算对称值】【3.整除2】

例如输入`label = 26`
将`label`加入数组
然后将`label`计算成26所在行的对称值`16+31-26=21`
再对`label`求除以2的商
循环至lable为0

![tmp.bmp](https://pic.leetcode-cn.com/410bedd6aa87eba8382ecf14abd24f03263c3e76220208baff7a91b692e815c3-tmp.bmp)


```Python
#28ms版本
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans = [label]
        while label:
            label = 3 * 2**(len(bin(label))-3) - 1 - label
            label //= 2
            ans.insert(0, label)
        return ans[1:]
#32ms版本
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans = [label]
        while label:
            label = 3 * 2**(len(bin(label))-3) - 1 - label
            label //= 2
            ans.append(label)
        return ans[:-1][::-1]
```