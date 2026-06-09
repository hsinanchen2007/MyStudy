其实这题还是蛮值得写一写的，虽然没什么惊世骇俗的算法，就是词典树；但我相信不少人是写不出来完整的，耐下心来写，避免眼高手低；对夯实基础很重要的：
```
import collections
class node():
    def __init__(self):
        self.is_word=False
        self.next=collections.defaultdict(node)
class Solution:
    def insert(self,word,root): #把单词插入字典树
        cur=root
        for i in word:
            cur=cur.next[i]
        cur.is_word=True
    def search(self,word,root):
        temp=''
        cur=root
        for i in word:
            if i not in cur.next:
                if(not cur.is_word): #两种情况，一种是含有前缀，那么is_word肯定是True，第二种是不含前缀，但可能有几个单词重叠，所以要清空temp
                    temp=''
                break
            cur=cur.next[i]
            temp+=i
            if(cur.is_word):
                return temp
        if(len(temp)==0):
            return -1
        return temp
    def replaceWords(self, dict, sentence):
        sentence=sentence.split()
        tree=node()
        for i in dict:
            self.insert(i,tree)
        for j in range(len(sentence)):
            temp=self.search(sentence[j],tree)
            if(temp!=-1):
                sentence[j]=temp
        return ' '.join(sentence)
```

