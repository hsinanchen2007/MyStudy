```
class Solution(object):
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        max_jumbo = tomatoSlices // 4
        max_small = tomatoSlices // 2
        if tomatoSlices % 2 or cheeseSlices>max_small or cheeseSlices<max_jumbo:
            return []
        diff = (tomatoSlices - 2 * cheeseSlices) // 2
        return [diff, cheeseSlices-diff]
```
