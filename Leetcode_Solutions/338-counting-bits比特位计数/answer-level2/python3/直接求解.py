    class Solution:
        def countBits(self, num: int) -> List[int]:
            res = []
            for i in range(num + 1):
                bin_num_count = bin(i).count('1')
                res.append(bin_num_count)
            return res
            