class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        '''双指针，两种情况
        1. 如果是插入或者删除，字符串长度必须相差1个，
        并且其中双指针某一个不同时，截取后面的应该是相同的
        2. 如果是替换， 那么只要一次不同，后面的就必须相同
        '''
        first_len = len(first)
        second_len = len(second)
        'first表示长度短点的字符'
        if first_len > second_len:
            first, second = second, first
            first_len, second_len = second_len, first_len
        
        if second_len - first_len > 1:
            return False
        
        for i in range(first_len):
            if first[i] == second[i]:
                continue
            else:
                return first[i:] == second[i+1:] or first[i+1:] == second[i+1:]
        '防止两个字符串都是空的情况'
        return True