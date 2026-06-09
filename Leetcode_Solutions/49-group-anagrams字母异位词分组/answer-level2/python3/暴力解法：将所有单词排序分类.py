![49通过.png](https://pic.leetcode-cn.com/34b0aa24f29cbb67e9cd42cc52c27262d48187b5691e9e97d87b71e8804145d7-49%E9%80%9A%E8%BF%87.png)

解题思路：若每个单词字母相同则排序后得到的字符串应一致，按照此规则遍历strs列表对单词进行分类
代码：

    class Solution:
        def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
            def wordmatch(word: str):
                w_list = list(word)
                w_list.sort()
                word_re = ""
                for i in w_list:
                    word_re += i
                return word_re
            
            word_dict = {wordmatch(strs[0]):[strs[0]]}
            for i in range(1, len(strs)):
                word = wordmatch(strs[i])
                # print(word)
                if word not in word_dict.keys():
                    word_dict[word] = [strs[i]]
                else:
                    word_dict[word].append(strs[i])
                # print('word_dict = ', end='')
                # print(word_dict)
            return word_dict.values()