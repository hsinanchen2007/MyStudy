```
from collections import Counter
count = sorted(Counter(s).items(), key=lambda x: -x[1])
res= ''
for i, v in count:
    res += i * v
return res
```
