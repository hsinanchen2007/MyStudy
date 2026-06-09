from functools import reduce
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits:
            dic={"2":["a","b","c"],"3":["d","e","f"],"4":["g","h","i"],"5":["j","k","l"],"6":["m","n","o"],"7":["p","q","r","s"],"8":["t","u","v"],"9":["w","x","y","z"]}
            return reduce(lambda x,y:[i+j for i in x for j in dic[y]],digits,[""])
        else:
            return []