直接遍历...

```
class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
        res = [[] for x in range(len(searchWord))]
        for i in range(len(searchWord)):
            counter = 0
            for j in range(len(products)):
                if searchWord[:i+1] == products[j][:i+1]:
                    res[i].append(products[j])
                    counter += 1
                if counter >= 3:
                    break
        return res
```
