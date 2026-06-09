class Solution:
    def isPalindrome(self, x: int) -> bool:
        list1 = list(str(x))
        list2 = reversed(list1)
        if list1 == list(list2):
            return True
        else:
            return False