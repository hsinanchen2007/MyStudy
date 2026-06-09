### 解题思路

### 代码

```python3
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        mydict = {'a':".-", 'b':"-...", 'c':"-.-.", 'd':"-..", 'e':".", 'f':"..-.", 'g':"--.",'h':"....", 'i':"..", 'j':".---", 'k':"-.-", 'l':".-..", 'm':"--", 'n':"-.", 'o':"---", 'p':".--.", 'q':"--.-", 'r':".-.", 's':"...", 't':"-", 'u':"..-", 'v':"...-", 'w':".--", 'x':"-..-", 'y':"-.--", 'z':"--.."}
        mosi = []
        for i in words:
            temp = ''
            for j in i:
                temp += mydict[j]
            mosi.append(temp)
        moset = set(mosi)
        return len(moset)
```