### 解题思路
此处撰写解题思路
1 明确问题：
求最小编辑距离
    编辑距离指什么：字符串插入、删除、替换的操作
    如何求最小？
        ->字符操作最少
        ->min(所有的操作路径集合（插入、删除、替换）长度最小)
2 明确思路
    暴力枚举->状态如何转移->
    对于两字符串的操作，一般搞两指针指向字符串末尾，从左到右移动指针，做选择
    s1='sea'，s2='ate'，将s1变成s2，初始p1=2,p2=2，明显s1[p1]<>s2[p2]
    1）假设只用插入，
    ##TO-DO



3 代码飞起



### 代码

```python3
class Solution:
    #将word1转换成word2
    def minDistance(self, word1: str, word2: str) -> int:
        #利用元组字典去除重复子问题
        res = dict()
        def dp(p1,p2):
            if (p1,p2) in res:
                return res[(p1,p2)]
            #p1到达边界,返回p2+1,即将p2及之前的字符插入到p1
            if p1 == -1:return p2+1
            #p2到达边界,返回p1+1,即将p1及之前的字符删除
            if p2 == -1:return p1+1
            #word1[p1]==word1[p1]，跳过
            if word1[p1] == word2[p2]:
                res[(p1,p2)] = dp(p1-1,p2-1)
            #word1[p1]！=word1[p1]，选择 插入；删除；替换 中最小的
            else:
                res[(p1,p2)] = min(dp(p1,p2-1),dp(p1-1,p2),dp(p1-1,p2-1))+1
            return res[(p1,p2)]
        
        return dp(len(word1)-1,len(word2)-1)


```