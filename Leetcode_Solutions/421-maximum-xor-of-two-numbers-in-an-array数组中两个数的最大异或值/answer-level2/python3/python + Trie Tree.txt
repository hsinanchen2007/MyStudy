```python
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # [3, 10, 5, 25, 2, 8]
        # [000101, 001010, 000101, 011001, 001000]
        # 000101
        # 011001
        # 011100 => 16 + 8 + 4 = 28

        # num => 32
        # 1000000... => True => 11 =>
        #               False => 10 =>
        # Time complexity: O(32N) => O(N)
        # Space complexity: O(N)

        def generate_trie_tree(trie, bit_nums):
            for bit_num in bit_nums:
                dic = trie
                for bit in bit_num:
                    dic = dic.setdefault(bit, {})
        
        def calculate(num, bit_num, trie):
            temp_res, dic = '', trie
            for i in range(len(bit_num)):
                if (bit_num[i] == '0' and '1' in dic) or (bit_num[i] == '1' and '0' not in dic):
                    temp_res += '1'
                    dic = dic['1']
                else:
                    temp_res += '0'
                    dic = dic['0']      
            return num ^ int(temp_res, 2)

        trie = {}
        bit_nums = ['{:032b}'.format(num) for num in nums]
        res = 0
        generate_trie_tree(trie, bit_nums)

        for i in range(len(nums)):
            res = max(res, calculate(nums[i], bit_nums[i], trie))
        return res
```