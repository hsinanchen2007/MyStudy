```
class Solution:
    def toGoatLatin(self, S: str) -> str:
        S = S.split()
        ans = [""] * len(S)
        end = "a"
        for i in range(len(S)):
            if not re.search(r"^[aeiouAEIOU]",S[i]):
                ans[i] = S[i][1:] + S[i][0]
            else:
                ans[i] = S[i]
            ans[i] += "ma" + end
            end += "a"

        return " ".join(ans)
```
