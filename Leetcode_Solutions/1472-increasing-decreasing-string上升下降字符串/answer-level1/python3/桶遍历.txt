def sortString(self, s: str) -> str:
        d = Counter(s)
        keys = sorted(list(d.keys()))
        new_s = ''
        while d:
            for k in keys:
                if d[k] >= 1:
                    new_s += k
                    d[k] -= 1
                    if d[k] == 0:
                        d.pop(k)
                if k == keys[-1]:
                    keys.reverse()
        return new_s