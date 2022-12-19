```
class Solution(object):
    def lenLongestFibSubseq(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        
        my_dict = {}

        for v in A:
            my_dict[v] = 1

        max_l = 0
        len_A = len(A)
        for i in range(len_A):
            for j in range(i+1, len_A):
                the_next_1 = A[j]    
                the_next_2 = A[i] + A[j]
                f_len = 2
                while my_dict.has_key(the_next_2):
                    f_len += 1
                    the_next_1, the_next_2 = the_next_2, the_next_1 + the_next_2
                if f_len > max_l:
                    max_l = f_len
        return max_l if max_l >= 3 else 0
```

用dict.has_key相比较val in list的方式应该能减少用时。