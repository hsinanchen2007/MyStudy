其实就是一个简单的python切片的使用，废话少说，看代码：

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if str(x)[::] == str(x)[::-1]:
            return True
        else:
            return False


这里解释下 x[::]和x[::-1]，x[::]就是从左向右取x的值，x[::-1]是从右向左取x的值，所以只要他俩相等，就是回文数。
