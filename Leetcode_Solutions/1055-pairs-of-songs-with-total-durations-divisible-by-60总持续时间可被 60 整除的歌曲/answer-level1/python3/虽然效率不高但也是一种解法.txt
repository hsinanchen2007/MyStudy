```
```
    def numPairsDivisibleBy60(self, time: List[int]) -> int:     
        a = {}
        count = 0
        for i in time:
            a[i % 60] = a.get(i % 60, 0)+1 # 构建一个字典
        a = dict(sorted(a.items(), key=lambda x: x[0])) # 按照key值排序
        for i, j in a.items():
            if i < 31:
                if i ==0 or i ==30:  # 为0 和30 时共有(n*(n-1))/2种结果
                    count += (a.get(i) * (a.get(i)-1))/2
                else:
                    if (60-i) in a.keys(): # 其他情况下,若60 -i在key值中排序结果为两个value相乘
                        count += (a.get(i)) * (a.get(60 - i)) 
            else:
                break
        return(int(count))
```
```
