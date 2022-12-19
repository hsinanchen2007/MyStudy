### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/7b1a91cdd838be2786cc9ee1c3e953afe95631ff3cd476c9ba9a21e67804c490-%E6%8D%95%E8%8E%B7.PNG)
1.遍历ransonNote,统计每个字符的数量，存入哈希表,遍历时如果在magazine没有找到，直接return False
2.遍历完后，遍历哈希表，如果每个字符的数量大于magazine该字符的数量，直接return False
3.完成上面两者，恭喜可以return True了
### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        store={}
        for i in ransomNote:
            if i not in magazine:return False
            if i not in store:
                store[i]=1
            else:store[i]+=1
        for key in store:
            if  magazine.count(key)<store[key]:return False
        return True

```