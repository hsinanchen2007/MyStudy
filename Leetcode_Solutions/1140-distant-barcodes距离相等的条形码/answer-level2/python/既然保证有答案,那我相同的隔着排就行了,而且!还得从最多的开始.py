```
#既然保证有答案,那我相同的隔着排就行了,而且!还得从最多的开始(贪心,尽力先挤掉最容易导致错误的)
        res , hm = [None for _ in range(len(barcodes))] , {}
        for i in barcodes:
            hm[i] = hm.get(i,0) + 1
        pos = 0
        for i in sorted(hm.keys() , key = lambda x: hm[x] , reverse = True):
            while hm[i] > 0:
                res[pos] = i
                hm[i] -= 1
                pos += 2
                if pos >= len(barcodes):
                    pos = 1
        return res
```
