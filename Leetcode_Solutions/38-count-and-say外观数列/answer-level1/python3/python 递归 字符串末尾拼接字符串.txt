### 解题思路
此处撰写解题思路
先上图，不解释！
![image.png](https://pic.leetcode-cn.com/e4d0e2acba7004bc831af05e0f62a10e63f317c8b1c7754fc5bf3fd8bbbe38f5-image.png)

根据报数题目，可以理解为图中拆分的，每个N值都会是能被2整除的序列，因为其中包含上一个数的count+num

# 重点思路（也是TMD困扰了我3小时没做出来的原因）
将字符串末尾处理一下拼接任意不是1~3之间的字符
即 1211 + "&" 组成新字符串 "1211&"

# 全部思路如下
1.递归（如果迭代请绕道）
2.找到最底层即n=1返回本身："1"
3.有了这个"1" 开始递归下面一层，即设定一个count=1（因为第一层已经有了一个1）
4.循环，条件①就是当：temp[i] != temp[i+1] 此时拼接temp[i]为 count + temp[i] (temp为上一层字符串)
![image.png](https://pic.leetcode-cn.com/72177608540fb759c3ac38090fbf8d84b1bffb1a3e75307dee18ca442c5c22b2-image.png)


### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if(n == 1): return '1'
        num = self.countAndSay(n-1)+"*"
        print(num)
        temp = list(num)
        count = 1
        strBulider = ''
        # print(len(temp))
        for i in range(len(temp)-1):
            if  temp[i] == temp[i+1] :
                    count += 1  
            else:
                if temp[i] != temp[i+1]:
                    strBulider +=  str(count) + temp[i]
                    count = 1
        return strBulider
```