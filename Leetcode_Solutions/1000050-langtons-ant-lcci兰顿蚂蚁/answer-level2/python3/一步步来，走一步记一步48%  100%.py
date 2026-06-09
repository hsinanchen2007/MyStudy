这里`list`里边把`str`写成`list`形式的话可能处理起来方便一点，毕竟python不允许内部修改`str`类型数据，
把所有情况都罗列一下，记录当前的位置`now`与颜色`color = '_' or 'X'`以及方向`d = L or R or U or D`，如果走的要边界，就在旁边加一行（列）`'_'`就好了。
最后更新一下最终的位置，把颜色换成方向即可。
```
def printKMoves(self, K: int) -> List[str]:
        color = '_'
        res = ['_']
        d = 'R'
        now = [0, 0]
        while K > 0:
            K -= 1
            if d == 'R':
                if color == '_':
                    res[now[0]] = res[now[0]][:now[1]] + 'X' + res[now[0]][now[1]+1:]
                    if now[0] == len(res)-1:
                        res.append('_'*len(res[0]))
                    d = 'D'
                    now[0] += 1
                    color = res[now[0]][now[1]]
                else:
                    res[now[0]] = res[now[0]][:now[1]] + '_' + res[now[0]][now[1]+1:]
                    if now[0] == 0:
                        res.insert(0, '_'*len(res[0]))
                        now[0] += 1
                    d = 'U'
                    now[0] -= 1
                    color = res[now[0]][now[1]]
            elif d == 'L':
                if color == '_':
                    res[now[0]] = res[now[0]][:now[1]] + 'X' + res[now[0]][now[1]+1:]
                    if now[0] == 0:
                        res.insert(0, '_'*len(res[0]))
                        now[0] += 1
                    now[0] -= 1
                    d = 'U'
                    color = res[now[0]][now[1]]
                else:
                    res[now[0]] = res[now[0]][:now[1]] + '_' + res[now[0]][now[1]+1:]
                    if now[0] == len(res)-1:
                        res.append('_'*len(res[0]))
                    d = 'D'
                    now[0] += 1
                    color = res[now[0]][now[1]]
            elif d == 'U':
                if color == '_':
                    res[now[0]] = res[now[0]][:now[1]] + 'X' + res[now[0]][now[1]+1:]
                    if now[1] == len(res[0]) - 1:
                        for i in range(len(res)):
                            res[i] += '_'
                    d = 'R'
                    now[1] += 1
                    color = res[now[0]][now[1]]
                else:
                    res[now[0]] = res[now[0]][:now[1]] + '_' + res[now[0]][now[1]+1:]
                    if now[1] == 0:
                        for i in range(len(res)):
                            res[i] = '_' + res[i]
                        now[1] += 1
                    d = 'L'
                    now[1] -= 1
                    color = res[now[0]][now[1]]
            else:
                if color == '_':
                    res[now[0]] = res[now[0]][:now[1]] + 'X' + res[now[0]][now[1]+1:]
                    if now[1] == 0:
                        for i in range(len(res)):
                            res[i] = '_' + res[i]
                        now[1] += 1
                    d = 'L'
                    now[1] -= 1
                    color = res[now[0]][now[1]]
                else:
                    res[now[0]] = res[now[0]][:now[1]] + '_' + res[now[0]][now[1]+1:]
                    if now[1] == len(res[0])-1:
                        for i in range(len(res)):
                            res[i] += '_'
                    d = 'R'
                    now[1] += 1
                    color = res[now[0]][now[1]]
        res[now[0]] = res[now[0]][:now[1]] + d + res[now[0]][now[1]+1:]
        return res

```
