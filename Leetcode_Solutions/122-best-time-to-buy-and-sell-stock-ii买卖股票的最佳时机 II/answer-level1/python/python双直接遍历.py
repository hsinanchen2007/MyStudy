直接上代码
```
if len(prices)<2: return 0
        benefits = [0]
        i, j, sum = 0, 1, 0
        for j in range(1, len(prices)):
            if prices[j] > prices[i] and prices[j]-prices[i] > benefits[-1]:
                benefits.append(prices[j]-prices[i])
            else:
                i = j
                sum += benefits[-1]
                benefits = [0]
        sum += benefits[-1]
        return sum
```
