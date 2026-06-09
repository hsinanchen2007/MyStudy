class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # for ind, val in enumerate(s):
        #     adict[ind] = val
        
        my_list = []
        max_list = []
        a = 0
        my_length = 0
        max_length = 0
        for i in range(len(s)):
            # if s[i] is None and i !=0:
            #     a += 1
            #     if a >1:
            #         my_list =my_list[my_list.index(s[i])+1:]
            #         a = 0
            #     # else:
            #         if len(max_list) < len(my_list):
            #              max_list = my_list

            if s[i] in my_list:        
                my_list =my_list[my_list.index(s[i])+1:]
            my_list.append(s[i])
            if len(max_list) < len(my_list):
                max_list = my_list
        return len(max_list)
    这是我目前能想到最短的==希望大佬们可以指导下