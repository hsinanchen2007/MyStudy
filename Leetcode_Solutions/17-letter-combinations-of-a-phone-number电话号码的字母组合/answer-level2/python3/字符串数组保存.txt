### 解题思路
例：2 * 4 * 7
s[0] = "aaaaaaaaaaaabbbbbbbbbbbbcccccccccccc"
s[1] = "gggghhhhiiiigggghhhhiiiigggghhhhiiii"
s[2] = "pqrspqrspqrspqrspqrspqrspqrspqrspqrs"
然后再拼:agp,agq,agr,ags,ahp,ahq,ahr,ahs,.....

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dict = {2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}

        length = len(digits)
        if length == 0:
            return []

        arr = []
        res = []

        for i in range(0,length):
            digit = int(digits[i])

            for key in dict:
                if key == digit:
                    arr.append(dict[key])
                    break

        # example: "abc" * "ghi" * "pqrs"
        count = 1
        for i in range(0,length):
            leni = len(arr[i])
            count *= leni

        s = []
        innerCount = count
        for i in range(0,length):
            si = ""
            innerCount //= len(arr[i])
            outerCount = count // innerCount

            for j in range(0,outerCount):
                for k in range(0,innerCount):
                    si += arr[i][j % len(arr[i])]

            s.append(si)

        for i in range(0,count):
            si = ""
            for j in range(0,length):
                si += s[j][i]

            res.append(si)

        return res

```