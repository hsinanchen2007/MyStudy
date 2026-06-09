因为是寻找最短路径，第一时间就想到了广度优先搜索，首先是单方向的搜索，以初始点为中心，一圈一圈向外扩，遇到终止点后，停止扩张，建立字典，键为节点，值为他的上游节点。
代码如下所示：
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        def compare(s1, s2):        #比较是否相差一个字符
            if len(s1) != len(s2):
                return False
            n = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    n += 1
                    if n == 2:
                        return False 
            return n == 1
        if endWord not in wordList:
            return []
        s1 = set([beginWord])       #轴心beginword
        d = {}
        while s1:
            stack = set([])
            for n in s1:
                for word in wordList:
                    if compare(n, word):
                        stack.add(word)
                        if word in d:
                            d[word].append(n)   #同一个点可能有多个上游点
                        else:
                            d[word] = [n]
            if endWord in d:
                break
            for w in stack:
                wordList.remove(w)
            s1 = stack.copy()
        if endWord not in d:
            return []
        else:                                  #扩充成路径
            path = [[endWord]]
            while path[0][0] != beginWord:
                tmp = []
                for i in range(len(path)):
                    for w in d[path[i][0]]:
                        tmp.append([w] + path[i])
                path = tmp[:]
            return path
不出所料，超时
思路二：双向广度优先搜索，求交集，思路和上一题类似，但是要拖家带口，把所有指向他的路径都带上，最后求两边路径最后一个点是否有关联，若有关联，拓展为路径 
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        import copy
        wordList = set(wordList)
        def compare(s1, s2):
            if len(s1) != len(s2):
                return False
            n = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    n += 1
                    if n == 2:
                        return False 
            return n == 1
        if endWord not in wordList:
            return []
        s1 = [[beginWord]]
        s2 = [[endWord]]
        i = 0
        re = []
        while s1:
            stack = []
            if i != 0:
                for n in s1:
                    if n[-1] in wordList:
                        wordList.remove(n[-1])
            word_list = []
            for path in s2:
                word_list.append(path[-1])
            for path in s1:
                for word2 in wordList:
                    if compare(path[-1], word2):
                        if word2 in word_list:
                            for j in range(len(s2)):
                                if s2[j][-1] == word2:
                                    tmp = s2[j][:]
                                    if tmp[0] == endWord:
                                        tmp.reverse()
                                        re.append(path + tmp)
                                    else:
                                        tmp_t = path[:]
                                        tmp_t.reverse()
                                        re.append(tmp + tmp_t)
                        else:
                            stack.append(path + [word2])
            if len(re) != 0:
                return re
            if len(stack) > len(s2):
                s1 = copy.deepcopy(s2) 
                s2 = copy.deepcopy(stack) 
            else:
                s1 = copy.deepcopy(stack) 
            i += 1
        return []
勉强通过，比较无脑的方法，权当做记录，请指教 