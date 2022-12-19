### 解题思路
使用递归的方法  
这道题其实跟斐波那契数列有点类似，都是基于上一项的结果得出下一项的结果，因此适合使用递归来解决问题。  
  
因为确定了`n=1`时的值，所以基线条件就可以设置为 `n <= 1` 时返回。  
![image.png](https://pic.leetcode-cn.com/d6bdae805075acfefc7bba932d275478aef1ad092d23ec834088d5cdeb0c6b1a-image.png)  

在后面的循环里，思路是当遇到的字符串与上一个相等的时候，计数器+1，否则结束计数，并将当前结果添加到`res`变量中，并且计数器恢复到1。  
比较需要注意的是边际条件，在字符串开头跟结尾的时候做了单独的处理。  
  
处理字符串开头的时候  
![image.png](https://pic.leetcode-cn.com/12c8f3df7006e473d4472ea83060b78e5b3333a5bffa972f07ee9afa744d029b-image.png)   
处理字符串末尾的时候  
![image.png](https://pic.leetcode-cn.com/73ca2588a4325317e704db813787ee1101db951b5fdda8b5f7c1496dadd7efae-image.png "边际条件处理")



### 代码

```python3

class Solution:
    def countAndSay(self, n: int) -> str:
        if n <= 1:
            return '1'
        pre = self.countAndSay(n - 1)

        res = ''
        count = 1
        for idx in range(len(pre)):

            if idx == 0 :
                count = 1

            elif pre[idx] != pre[idx -1]:
                tmp = str(count) + pre[idx-1]
                res += tmp
                count = 1
            elif pre[idx] == pre[idx-1]:
                count +=1

            if idx == len(pre) - 1:
                tmp = str(count) + pre[idx]
                res += tmp
        return res

```