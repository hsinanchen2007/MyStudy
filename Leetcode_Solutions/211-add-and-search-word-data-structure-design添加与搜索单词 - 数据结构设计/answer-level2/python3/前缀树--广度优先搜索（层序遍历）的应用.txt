### 解题思路
前缀树的添加节点就不说了，搜索节点这里遍历`word`各字符，从前缀树中逐层搜索。
当为'.'，将本层全部节点的子节点作为下次搜索对象，
当非'.'，将本层对应字符的节点作为下次搜索对象。
最后求当前搜索对象的`isword`标签是否有True。
### 解题代码
```python
class WordDictionary:

    def __init__(self,val='',isword=False):
        self.val = val
        self.isword=isword ## 以此节点结尾的字符串是否是完整单词
        self.children = [] 

    def addWord(self, word: str) -> None:
        cur = self
        for i in word:
            try: ## 尝试访问val为i的节点
                cur = [x for x in cur.children if x.val==i][0]
            except: ## 无此节点，生成并存入子节点列表，并访问该子节点
                cur.children.append(WordDictionary(i))
                cur = cur.children[-1]                
        cur.isword=True ## 添加结束，最后字符是完整单词

    def search(self, word: str) -> bool:
        curs = [self] ## 初始化层序遍历指针
        for v in word:              
            curs = [y for x in curs for y in x.children] ## 子节点列表
            if v!='.': curs = [y for y in curs if y.val==v] ## 选出val为v的节点的列表
        return any([x.isword for x in curs]) ## 列表中是否有完整单词
```
### 执行结果
执行用时 :432 ms, 在所有 Python3 提交中击败了26.21%的用户
内存消耗 :23.9 MB, 在所有 Python3 提交中击败了55.96%的用户
