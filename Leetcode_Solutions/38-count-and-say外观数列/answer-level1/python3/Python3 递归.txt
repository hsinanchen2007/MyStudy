```
class Solution:
    def countAndSay(self, n: int) -> str:
        def count(str):
            cnt_lst = []
            length = len(str)
            i = 0
            while i < length:
                cnt = 1
                while i < length - 1 and str[i] == str[i+1]:
                    cnt += 1
                    i += 1
                cnt_lst.append((cnt, str[i]))
                i += 1
            return cnt_lst

        def say(cnt_lst):
            num = ''
            for cnt, ele in cnt_lst:
                num += str(cnt) + ele
            return num

        if n == 1:
            return '1'

        return say(count(self.countAndSay(n-1)))
```
