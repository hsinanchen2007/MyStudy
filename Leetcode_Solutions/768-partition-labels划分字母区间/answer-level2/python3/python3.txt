
```
class Solution:
    result = []
    def partitionLabels(self, S: str) -> List[int]:
        self.result = []
        s_len = len(S)
        def find_list(self, s):
            if not s:
                return
            end_id = 0
            out_id = len(s) - 1
            for i in range(len(s)):
                end_id = max(s.rfind(s[i]), end_id)
                if i == end_id:
                    self.result.append(i + 1)
                    out_id = i
                    break
            if out_id >= len(s) - 1:
                return
            else:
                find_list(self, s[out_id+1:])
        find_list(self, S)
        return self.result
```
