

改编自折半查找，找到元素后，再做一个左右扩展搜索，确定首尾坐标。


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 折半查找 
        s_pos, e_pos = -1, -1
        
        n_nums = len(nums)
        
        l_pos, r_pos = 0, n_nums - 1
        
        while l_pos <= r_pos:
            m_pos = (l_pos + r_pos) // 2
            if target == nums[m_pos]:
                s_pos, e_pos = m_pos, m_pos
                while e_pos + 1 < n_nums:
                    if nums[e_pos + 1] == target:
                        e_pos += 1
                    else:
                        break
                while s_pos > 0:
                    if nums[s_pos - 1] == target:
                        s_pos -= 1
                    else:
                        break
                return [s_pos, e_pos]
            elif target > nums[m_pos]:
                l_pos = m_pos + 1
            elif target < nums[m_pos]:
                r_pos = m_pos - 1
            
        return [s_pos, e_pos]