```
import re
class Solution:
    def replaceSpace(self, s: str) -> str:
        res = re.sub('\s', '%20', s)
        return res
```

