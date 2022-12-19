代码不够优雅，但是处理速度快，内存占用也不大


class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        key_dic = dict()
        # 创建字典，键为keyboard的字符，值为索引位置，因为字典遍历速度快于列表   
        for index, key_board in enumerate(keyboard):
            key_dic[key_board] = index
        # 这里flag用于保存上一次的索引位置，进而求差值可以得到键盘的时间，-1是因为索引均为正，-1可以用于表示初始位置，这里也可以使用其他的标记
        # 例如"start"等，可以避免魔鬼数字的产生
        flag = -1
        # 用于保存累计的时间
        time = 0
        for single_word in word:
            # 从索引字典中找到目前字符的索引位置
            single_word_index = key_dic[single_word]
            # 用于判断第一个字符的时间
            if flag == -1:
                time += abs(single_word_index - 0)
            # 用于计算后续其他字符的时间
            else:
                time += abs(single_word_index - flag)
            # 保存上一次的索引位置
            flag = single_word_index
        return time