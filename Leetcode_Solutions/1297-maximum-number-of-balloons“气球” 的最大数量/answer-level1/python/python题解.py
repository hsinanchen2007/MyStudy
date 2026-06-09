```
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        text_count = collections.Counter(text)
        result = []
        print(text_count)
        for key in set("balloon"):
            if key in text_count:
                if key == 'l' or key == 'o':
                    result.append(text_count[key]//2)
                else:
                    result.append(text_count[key])
            else:
                return 0

        return min(result)
```
