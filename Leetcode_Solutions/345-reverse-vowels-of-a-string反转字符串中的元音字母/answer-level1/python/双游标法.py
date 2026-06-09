思路：设置一个list存放所有的元音字母，共计十个。设置两个游标分别从左右两次计数，不是元音字母，继续向中间移动，如果遇到元音字母，就和另一个方向的元音字母交换。直到游标相遇为止

`    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a', 'e', 'i', 'o', 'u', "A", "E", "I", "O", "U"]
        list_s = list(s)

        low, high = 0, len(s) - 1
        while low < high:
            if list_s[high] not in vowels:
                high -= 1
            if list_s[low] not in vowels:
                low += 1
            if list_s[low] in vowels and list_s[high] in vowels:
                list_s[low], list_s[high] = list_s[high], list_s[low]
                low += 1
                high -= 1
        return "".join(list_s)`