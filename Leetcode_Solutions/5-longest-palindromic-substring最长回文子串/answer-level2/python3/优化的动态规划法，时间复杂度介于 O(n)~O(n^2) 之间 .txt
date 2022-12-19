
优化的动态规划法，时间复杂度介于 O(n)~O(n^2) 之间 


    length = len(s_)
    max_huiwen_len = 0        #保存最大回文字符串的长度
    huiwen_str = ''           #保存最大回文字符串

    for left_i in range(length):
        scale = 0
        for j in range(left_i+1, length):
            if s_[left_i] != s_[j]: break
            scale += 1

        right_i = left_i + scale    #对于 cbbd 情况，left_i 是 1， right_i 是 2，即 bb

        #以 left_i:right_i 之间的回文串为基础，左右扩展，以寻找更长的回文串
        huiwen_i = 1
        while left_i - huiwen_i >=0 and right_i + huiwen_i < length and s_[left_i-huiwen_i] == s_[right_i+huiwen_i]:
            huiwen_i += 1
        else:
            huiwen_i -= 1    #无论如何， huiwen_i 都要减去 1 ，因为 huiwen_i 从 1 开始
     
        left_i -= huiwen_i    #找出的回文串的左边下标
        right_i += huiwen_i    #找出的回文串的右边下标
        huiwen_length = right_i - left_i + 1    #找到的回文串的长度
        if huiwen_length > max_huiwen_len:
            max_huiwen_len = huiwen_length
            huiwen_str = s_[left_i:right_i+1]
    return huiwen_str



