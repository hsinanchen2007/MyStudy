参照这位大佬[@koukou-11](/u/koukou-11/)的java代码，个人感觉他的想法很优雅，类似于操作系统中信号量机制

```
        R, D = True, True
        senate = list(senate)
        person = 0
        while R and D:
            R, D = False, False
            for i in range(len(senate)):
                if senate[i] == 'R':
                    R = True
                    if person < 0:
                        senate[i] = '0'
                    person += 1
                elif senate[i] == 'D':
                    D = True
                    if person > 0:
                        senate[i] = '0'
                    person -= 1
        return "Radiant" if person > 0 else "Dire"
```
