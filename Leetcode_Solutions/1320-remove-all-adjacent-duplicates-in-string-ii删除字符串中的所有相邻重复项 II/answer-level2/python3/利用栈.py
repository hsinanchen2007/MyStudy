class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        ans = ""
        count = []
        strs = "abcdefghijklmnopqrstuvwxyz"
        for i in strs:
            t = i*k
            while t in s:
                s = s.replace(t,"")
        last = ""
        lenth = 0
        for i in s:
            ans += i
            lenth += 1
            if i != last:
                count.append(1)
            else:
                count[-1] += 1
                if count[-1] == k:
                    count.pop()
                    ans = ans[0:lenth-k]
                    lenth -= k
            last = ans[-1] if ans else ""
        return ans
        