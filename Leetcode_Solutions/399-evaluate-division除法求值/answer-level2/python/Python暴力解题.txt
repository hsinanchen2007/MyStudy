# Python笨办法，暴力解题
尝试了很多次终于做出来了。
![Capture.PNG](https://pic.leetcode-cn.com/c8326d94ff3ad42ff58acd79606f128fd705618309c6fa80f64fcacc2a56ae19-Capture.PNG)
```
class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        k = 1
        var = []
        dict = {}
        rel = [equations[0]]
        res = []
        n = 0
        for (x, y), v in zip(equations, values):
            var.append((x, y, v))
            for i in range(len(rel)):
                if x in rel[i] or y in rel[i]:
                    if x not in rel[i]:
                        rel[i].append(x)
                    if y not in rel[i]:
                        rel[i].append(y)
                else:
                    rel.append([x, y])
                    break
    
        dict[var[0][0]] = var[0][2] * k
        dict[var[0][1]] = k
        del var[0]
    
        while len(var) >= 1:
            de = []
            n += 1
            for i in range(len(var)):
                if var[i][0] in dict:
                    dict[var[i][1]] = dict[var[i][0]] / var[i][2]
                    de.append(i)
                    n = 0
                elif var[i][1] in dict:
                    dict[var[i][0]] = var[i][2] * dict[var[i][1]]
                    de.append(i)
                    n = 0
            
            var = [var[i] for i in range(len(var)) if i not in de]
            
            if n >= len(var) and n > 0:
                dict[var[0][0]] = var[0][2] * k
                dict[var[0][1]] = k
                del var[0]
        
        for i in range(len(rel)):
            if i >= len(rel):
                break
            for j in range(i + 1, len(rel)):
                if j >= len(rel):
                    break
                for m in rel[j]:
                    if m in rel[i]:
                        for x in rel[j]:
                            if x not in rel[i]:
                                rel[i].append(x)
                        #rel[i].append(x for x in rel[j] if x not in rel[i])
                        del rel[j]
                        break
                    
                
        for i in queries:
            i.append(-1.0)
            for j in rel:
                if i[2] == -1.0 and i[0] in j and i[1] in j:
                    i[2] = 0
            if i[2] == 0:
                i[2] = dict[i[0]] / dict[i[1]]
            res.append(i[2])
            
        return res
```
