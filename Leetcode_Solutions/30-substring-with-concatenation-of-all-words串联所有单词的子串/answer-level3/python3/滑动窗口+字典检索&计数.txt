- 每次遇到看起来难的题，首先，我总是会试着从人脑思维或者其他课程知识来寻找帮助
- 于是，这里我想到了计网的“滑动窗口”知识点
- 思路十分简单：
- 1.确定窗口长度：len 为 words 中所有不重复单词的总长度
- 2.窗口滑动：每次移动一格，并以一个单词长度为单位进行滑动判断，若一旦不满足，则停止滑动
- 3.将满足条件的起始位置保存
```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        write = []
        if len(words) == 0:
            return []
        if len(s) < len(words)*len(words[0]):
            return []
        dic = {}
        flag = 0
        for i in words:
            try:
                dic[i]+=1
            except KeyError:
                dic[i]=1
                flag+=1
                write.append(i)
        #是否存在用字典查看
        left, right = 0, len(words)*len(words[0])
        #滑动窗口
        while right<=len(s):
            n,start = 0,left
            per = len(words[0])
            tag = dict(zip(write,[0]*flag))
            while n < len(words):
                #若存在于字典中
                if dic.get(s[start:start+per]):
                    if tag[s[start:start+per]] < dic[s[start:start+per]]:
                        tag[s[start:start+per]] += 1
                        n+=1
                        start+=per
                    else:
                        break
                else:
                    break
            if n == len(words):
                res.append(left)
            left+=1
            right+=1
        return res
```
