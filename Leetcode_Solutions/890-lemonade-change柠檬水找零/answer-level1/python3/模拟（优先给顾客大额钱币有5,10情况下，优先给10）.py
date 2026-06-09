```
class Solution:
    def lemonadeChange(self, bills) -> bool:
        if bills == []:
            return True
        have = {}
        for i in range(bills.__len__()):
            if bills[i] == 5:
                if 5 not in have.keys():
                    have[5] = 1
                else:
                    have[5] += 1
            else:
                back = bills[i] - 5
                if back not in have.keys():
                    if back == 5:
                        return False
                    elif back == 15:
                        if 5 in have.keys() and have[5] >= 1 and 10 in have.keys() and have[10] >= 1:
                            have[5] -= 1
                            have[10] -= 1
                            continue
                        if 5 in have.keys() and have[5] >= 3:
                            have[5] = have[5] - 3
                            continue
                        return False
                else:
                    have[back] -= 1
                    if bills[i] not in have.keys():
                        have[bills[i]] = 1
                    else:
                        have[bills[i]] += 1
        return True
```
