```
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        wallet = {
            '5': 0,
            '10': 0,
            '20': 0
        }

        for item in bills:
            if item == 5:
                wallet['5'] += 1
                continue
            if item == 10:
                if wallet['5'] == 0:
                    return False
                wallet['5'] -= 1
                wallet['10'] += 1
                continue
            if item == 20:
                if wallet['5'] == 0:
                    return False
                if wallet['10'] == 0 and wallet['5'] < 3:
                    return False
                if wallet['10'] > 0:
                    wallet['10'] -= 1
                    wallet['5'] -= 1
                else:
                    wallet['5'] -= 3
                wallet['20'] += 1
        return True
```
