class Solution:
    def findLUSlength(self, strs) -> int:
        num = [len(i) for i in strs]  # 记录每个字符串长度
        max_len = max(num)  # 找出最长的字符

        if num.count(max_len) == 1:  # 如果长度最大的字符串只有一个
            return max_len          # 则返回当前最大长度
        equal = []  # 存储具有max_len长度的字符串
        while max_len in num:   # 把所有具有最大长度的字符串从strs吐出来，方便后边判断或者递归
            equal.append(strs.pop(num.index(max_len)))
            num.pop(num.index(max_len))
        if len(set(equal)) == 1:    # 如果存储最大字符串的equal列表只有一种字符串，可以判定最长的有重复，比如["gxkcheu", "gxkcheu"]
            if len(strs) == 0:      # 除去最长的那些字符串后，strs如果为空，则返回-1(没数可以进行迭代了，比如["gxkcheu", "gxkcheu"])
                return -1
            if len(strs) == 1:  # 如果剩下的只有一个，判断其是不是最长字符串的字串
                if strs[0] in equal[0]: # 如果是，返回-1，比如输入["gxkcheu", "gxkcheu","gxk"]
                    return -1
                return len(strs[0]) # 否则就返回 剩下这一个数的长度，比如输入["gxkcheu", "gxkcheu","gxa"]
            dict_del = []   # 定义一个空列表，用于保存待会要从strs中排除掉的项，我们并不是直接就把除了最长字符串之外的数就扔进去递归的，还要进行一个简单的判断，判断是不是最长字符串的子串
            for i in strs:  # 将除去最长字符串的strs遍历
                if i in equal[0]:   # 如果i直观的属于最长字符串的字串，那么在黑名单dict_del中记录中记录下来，等遍历完毕后将其从strs中移除
                    dict_del.append(i)
                    continue
                if len(i) > 1:  # 如果不是直观的子串，需要进行更深层的判断，比如"aabbcc", "cb"，"bc"，abc not in aabbcc ,但abc确实aabbcc的字串
                    pointer = 0  # 记录位置的指针
                    count = 0  # 纪录是否有逆序的字符串
                    list1 = equal[0]    
                    for j in i: 
                        if j in list1:  # 如果字符在最长字符串中
                            pointer = list1.index(j)    # 找出字符的位置
                            list1 = list1[pointer + 1:] # 截取该字符之后的部分进行判断
                        else:
                            count += 1  # 如果不在最长字符串中，count+1
                            break       
                        if j not in equal[0]:
                            break
                    if not count:
                        dict_del.append(i)
                continue
            for i in dict_del:
                num = strs.index(i)
                del strs[num]
            if strs:
                return self.findLUSlength(strs)
            return -1
        else:
            for i in set(equal):
                if equal.count(i) == 1:
                    return len(i)
            if len(strs):
                return self.findLUSlength(strs)
            return -1
