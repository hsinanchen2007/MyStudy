```
def findLadders(beginWord: str, endWord: str, wordList):
    # you题意可知，在从开始字符beginWord->endWord,途中只能改变一个字符
    # 因此难点如下：
    # 1. 一个单词，改变一个字符后，可能有多个单词匹配。所以需要一层多次遍历
    # 2. beginWord->endWord过程中，是需要递归去遍历的，直到能够到达endWord
    # 3. 如何有效确定一个单词，改变一个字符后，有哪些单词匹配 (可以提前使用*代替一个单词，进行字典存储有哪些单词与之相同)
    # 4. 每一次遍历的过程需要存储，并且在返回是需要回溯
    # 因此代码逻辑如下：

    # 如果endWord不在字典中，直接结束，或者所给数据为空
    if endWord not in wordList or not endWord or not beginWord or not wordList:
        return [ ]

    # 存储单词能够匹配哪些单词
    dp, l = {}, len(beginWord)
    for w in wordList:
        for i in range(l):
            if w[ :i ] + '*' + w[ i + 1: ] in dp:
                dp[ w[ :i ] + '*' + w[ i + 1: ] ].append(w)
            else:
                dp[ w[ :i ] + '*' + w[ i + 1: ] ] = [ w ]

    res = [ beginWord ]
    # 因为是递归，而且一个单词可能匹配到相同的单词，
    # 所以需要另开存储去存储已经遍历过的路径
    # 如果遍历过了，那直接返回即可
    demo = {}
    def backTracking( w, dp, value, start ):
        nonlocal demo
        # print(value)
        # 找到即可返回，不再递归
        if value and value[ -1 ] == endWord:
            res.extend([ v for v in value ])
            return True
        # 防止多次遍历同一条路径
        if w in demo:
            return
        demo[ w ] = True
        # 由于不同单词有多个字符，所以需要不同的替换字符，找到匹配词
        for i in range(len(w)):
            if w[ :i ] + '*' + w[ i + 1: ] not in dp or not dp[ w[ :i ] + '*' + w[ i + 1: ] ]:
                continue
            # 记录当前的匹配词，用于回溯
            ww = dp[ w[ :i ] + '*' + w[ i + 1: ] ]
            # 已经遍历过的词语，需要把dp置为空，防止同一路径再次放回，造成死循环
            dp[ w[ :i ] + '*' + w[ i + 1: ] ] = [ ]
            # 递归匹配词语
            for j in range(len(ww)):
                if ww[ j ] in value:
                    continue
                value.append(ww[ j ])
                if backTracking(ww[ j ], dp, value, j + 1):
                    return True
                # 回溯到父节点
                value.pop()
            # 回溯
            dp[ w[ :i ] + '*' + w[ i + 1: ] ] = ww
        return False

    if backTracking(beginWord, dp, [ ], 0):
        # 因为beginWord可能在wordList，也可能不在，所以需要选择一下
        if res[ 0 ] == res[ 1 ]:
            return res[ 1: ]
        return res
    return [ ]
```
