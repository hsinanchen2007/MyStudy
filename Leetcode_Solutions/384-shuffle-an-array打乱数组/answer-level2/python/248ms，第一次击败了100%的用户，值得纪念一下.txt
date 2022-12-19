

```
import random
import copy
class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.list = nums
        self.orig_list = copy.deepcopy(self.list)

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.orig_list


    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        random.shuffle(self.list)
        return self.list
```
