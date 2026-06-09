
思路：

1.全排列借鉴排列组合数，对于排列数，n的全排列等于n!，即 n = 3，P(3) = 3 x 2 = 6, n = 4, P(4) = 4 x 3 x 2 = 24
2. 按照如上思路，可以递归实现，对于2个元素，排列就是 A, B 和 B, A
3. 对于3个数，拆成 1个数和另外两个数，即 C, A, B 排列就是 C 和 B，A全排列的排列，这样就可以得到 把 C分别插到前一个前排列的 起始，中间和结尾。
4. 以此类推，该实现用的临时空间较多，可能不够优化，不过可以解决问题。 

Python:

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n_nums = len(nums)
        
        if n_nums < 2:
            return [nums]
        
        ret_list = self.recurPermute(nums[0:-1], nums[-1])
        return ret_list
        
        
    def recurPermute(self, nums, elem):
        n_nums = len(nums)
        new_list = []
        if n_nums == 1:
            return [[nums[0], elem], [elem, nums[0]]] 
        else:
            save_list = self.recurPermute(nums[0:-1], nums[-1])
            n_rsts = len(save_list)
            for i in xrange(0, n_rsts):
                for j in xrange(0, n_nums+1):
                    tmp = save_list[i][:]
                    tmp.insert(j, elem)
                    new_list.append(tmp)
            return new_list
        

Python 3:


class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n_nums = len(nums)
        
        if n_nums < 2:
            return [nums]
        
        ret_list = self.recurPermute(nums[0:-1], nums[-1])
        return ret_list
        
        
    def recurPermute(self, nums, elem):
        n_nums = len(nums)
        new_list = []
        if n_nums == 1:
            return [[nums[0], elem], [elem, nums[0]]] 
        else:
            save_list = self.recurPermute(nums[0:-1], nums[-1])
            n_rsts = len(save_list)
            for i in range(0, n_rsts):
                for j in range(0, n_nums+1):
                    tmp = save_list[i].copy()
                    tmp.insert(j, elem)
                    new_list.append(tmp)
            return new_list