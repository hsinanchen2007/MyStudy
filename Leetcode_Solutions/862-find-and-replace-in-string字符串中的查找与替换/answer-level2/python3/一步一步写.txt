```
S = list(S)
        for i in range(0, len(indexes)):
            h = len(sources[i])
            if ''.join(S[indexes[i]:indexes[i]+h]) == sources[i]:
                S[indexes[i]] = targets[i]
                if h > 1:
                    for j in range(indexes[i]+1, indexes[i]+h):
                        S[j] = ''
        return ''.join(S)
```
