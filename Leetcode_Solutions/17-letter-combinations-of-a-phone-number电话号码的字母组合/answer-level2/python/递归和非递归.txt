## 思路：

### 思路1：递归

递归过程中记录组合。

### 思路 2：迭代

类似 `BFS`，每次更新一个字母

## 代码:

### 思路 1：

```Python []
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        lookup = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }
        if not digits:
            return []
        n = len(digits)
        res = []
        def helper(i,tmp):
            if i == n:
                res.append(tmp)
                return 
            for alp in lookup[digits[i]]:
                helper(i+1,tmp+alp)
        helper(0,"")
        return res
```
```Java []
class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) {
            return new ArrayList();
        }
        Map<Character, String> map = new HashMap<Character, String>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
        List<String> res = new LinkedList<String>();
        helper("", digits, 0, res, map);
        return res;

    }

    private void helper(String s, String digits, int i, List<String> res, Map<Character, String> map) {
        if (i == digits.length()) {
            res.add(s);
            return;
        }
        String letters = map.get(digits.charAt(i));
        for (int j = 0; j < letters.length(); j++){
            helper(s+letters.charAt(j),digits,i+1,res,map);
        }
        
    }
}
```

### 思路 2：

```Python []
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        lookup = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }
        if not digits:
            return []
        res = [""]
        for num in digits:
            next_res = []
            for alp in lookup[num]:
                for tmp in res:
                    next_res.append(tmp + alp)
            res = next_res
        return res
```

```C++ []
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
```

