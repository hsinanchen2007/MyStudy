```python3
class Solution:
    def countDigitOne(self, n):
        s = str(n)
        count = 0
        for i in range(len(s)):
            high_level = s[:i]
            low_level = s[i+1:]
            if high_level == "":
                high = 1
            else:
                high = int(high_level)+1
            if low_level == "":
                low = 1
            else:
                low = int(low_level)+1
            if s[i] == '1':
                count += (high-1)*10**(len(low_level))+low
            elif s[i] == '0':
                count += (high-1)*10**(len(low_level))
            else:
                count += high*(10**(len(low_level)))
        return count