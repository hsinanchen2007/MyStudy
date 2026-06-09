### 解题思路
遍历字符串，因为是循环的，所以将遍历的字符+26再去减target，但是最后还是要取余数26.
注意点 这里面temp不能为0.也就是不能为target自身

### 代码

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min = INT_MAX;
        char res;
        for(char c : letters){
            int temp = (c + 26 - target)%26;
            if(temp<min && temp){
                min = temp;
                res = c;
            }
        }
        return res;
    }
};
```