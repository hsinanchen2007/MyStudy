```
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        path = []
        ans = 0
        for name in input.split("\n"):
            l = 0
            for c in name:
                if c == "\t":
                    l += 1
                else:
                    break
            if len(path) > l:
                for i in range(len(path) - l):
                    path.pop()
            path.append(name.strip("\t"))
            if "." in name:
                length = sum([len(p) for p in path]) + len(path) - 1
                ans = max(ans, length)
                print(path)
        return ans
```
