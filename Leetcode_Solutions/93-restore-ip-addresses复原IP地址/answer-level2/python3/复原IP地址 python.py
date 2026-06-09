```PYTHON3
class Solution:
    
    def restoreIpAddresses(self, s: str) -> List[str]:
        self._s = s
        self.length = len(s)
        self.output, self.segments = [], []
        self.backtrack()
        return self.output

    def is_valid(self, segment):
        return int(segment) <= 255 if segment[0] != '0' else len(segment) == 1

    def update_output(self, curr_pos):
        segment = self._s[curr_pos+1:self.length]  # 最后的一部分，是curr_pos+1
        if self.is_valid(segment):
            self.segments.append(segment)
            print(self.segments)
            self.output.append(".".join(self.segments))
            self.segments.pop()

    def backtrack(self, pre_pos=-1, dots=3):
        for curr_pos in range(pre_pos + 1, min(self.length - 1, pre_pos + 4)):
            # print(pre_pos+1,curr_pos+1)
            segment = self._s[pre_pos + 1:curr_pos + 1]
            if self.is_valid(segment):
                self.segments.append(segment)
                if dots - 1 == 0:
                    self.update_output(curr_pos)
                else:
                    self.backtrack(curr_pos, dots - 1)
                self.segments.pop()
```