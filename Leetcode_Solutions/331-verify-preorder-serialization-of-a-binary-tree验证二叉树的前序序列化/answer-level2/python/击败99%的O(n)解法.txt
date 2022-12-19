![搜狗截图20年01月28日1709_1.png](https://pic.leetcode-cn.com/8aeddadf94dc94cf206be71a2660bcb7e4dec6f2667b850c6eb3e5a6d4c853d5-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B401%E6%9C%8828%E6%97%A51709_1.png)

执行用时 :24 ms, 在所有 Python3 提交中击败了99.53%的用户
内存消耗 :13.3 MB, 在所有 Python3 提交中击败了57.86%的用户

主要思想：
1.num初始化为1，表示还可以出现#的个数
2.循环preorder：
①当遇到非#时：num++
②当遇到#：num--
3.num一旦为0时，意味着树已完成遍历，后面不应再有任何字符，否则False
```
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        num=1
        preorder=preorder.split(',')
        for i in preorder:
            if num==0:return False
            if i =='#':
                num-=1
                if num<0:return False
            else:
                num+=1
        if num==0:return True
        else:return False
```
