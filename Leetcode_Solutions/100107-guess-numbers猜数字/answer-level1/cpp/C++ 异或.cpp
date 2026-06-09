由于限定了长度和次数，而异或可以判断两个数字是否相同(相同数字异或结果为0)，所以取三次异或取非的和即可得到结果。
```
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return !(guess[0]^answer[0]) + !(guess[1]^answer[1]) + !(guess[2]^answer[2]);
    }
};
```
