def romanToInt(s):
    d = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    sum = 0
    index = -1
    special_word = False
    for key in s:
        index += 1
        if  special_word :#如果当前字符对象已经与其前一个字符组成了特殊单词，那么这个字符的值不要累计，直接进行一下次迭代
            special_word = False#恢复现场，下一次迭代使用
            continue
        else:#处理要记入计算的字符
            if len(s) != index+ 1  and d.get(key) >= d.get(s[index + 1]):  # 使用逻辑短路机制防止下表越界
                sum += d.get(key)
            if len(s) != index+ 1  and d.get(key) < d.get(s[index + 1]):  # 当前字符与后字符组成了"特殊单词"
                sum += d.get(s[index + 1]) - (d.get(key))
                special_word = True  # 后面的字符就作为【不计入计算的字符，直接continue】
            if len(s) == index + 1:#防止索引越界，最后一位单独处理
                sum += d.get(s[-1])
    return sum