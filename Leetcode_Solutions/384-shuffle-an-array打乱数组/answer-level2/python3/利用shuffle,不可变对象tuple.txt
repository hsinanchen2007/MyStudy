class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        self.tup = tuple(nums)
        

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.tup
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        import random
        x = self.nums
        _int = int
        for i in reversed(range(1, len(x))):
        # pick an element in x[:i+1] with which to exchange x[i]
            j = _int(random.random() * (i + 1))
            x[i], x[j] = x[j], x[i]
        return x