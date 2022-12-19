### 解题思路
解法比较简单，通过双指针遍历

值得注意的是通过实验，对于不变的元素
（代码中'a','e','i','o','u','A','E','I','O','U'部分）
运行时间上 列表 > 元祖 > 集合
 
![屏幕快照 2020-03-08 下午2.54.51.png](https://pic.leetcode-cn.com/11e810baedb01bdfd025d59b81b8602e4ea7d724fb66cd5113ce5d588c8e64fe-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-08%20%E4%B8%8B%E5%8D%882.54.51.png)

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        # a e i o u                                         #元音元素
        dic = {'a','e','i','o','u','A','E','I','O','U'}     #大小写元音元素集合作为判断依据
        pol = 0                                             #左指针
        por = len(s)-1                                      #右指针
        s_ = list(s)                                        #str类型数据无法直接查询in和not in，转换为list
        while pol < por:                                    #左右指针交错循环停止
            if s_[pol] in dic and s_[por] in dic:           #左右指针所指元素均在集合中
                s_[pol], s_[por] = s_[por], s_[pol]         #交换左右指针所指元素
                por -= 1                                    #右指针左移
                pol += 1                                    #左指针右移
            if s_[por] not in dic:                          #右指针所指元素不在集合中
                por -= 1                                    #右指针左移
            if s_[pol] not in dic:                          #左指针所指元素不在集合中
                pol += 1                                    #左指针右移
        return ''.join(s_)                                  #返回str格式数据
```