感觉性能不够优化

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        ret_list = []
        n_words = len(words)
        if n_words > 0:
            n_sub_words = len(words[0])
        else:
            return ret_list
        n_tlt_alphas = n_words * n_sub_words
        s_len = len(s)
        for i in range(0, s_len - n_tlt_alphas + 1):
            sample_str = s[i:i+n_tlt_alphas]
            if self.sub_match(sample_str, words, n_tlt_alphas, n_sub_words):
                ret_list.append(i)
        return ret_list
        
        
    def sub_match(self, sample_str, words, tlt_len, sub_len):
        tmp_words = words[:]    
        for i in range(0, tlt_len, sub_len):
            sub_str = sample_str[i:i+sub_len]
            try:
                idx = tmp_words.index(sub_str)
            except ValueError:
                return False
            else:
                tmp_words.pop(idx)
            
        return True