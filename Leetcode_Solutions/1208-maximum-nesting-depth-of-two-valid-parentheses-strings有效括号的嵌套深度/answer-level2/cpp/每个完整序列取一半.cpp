### 解题思路
- 先处理出字符串中所有完整的序列深度
- 将每个完整序列分出一半给A, 剩下的一半给B即可(从外剥壳)
- 用时4ms，空间7.6MB

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // rec记录每一个完整的括号序列的深度
        // 例如"((()))(())()"的rec为[3, 2, 1]
        vector<int> rec;
        // left表示当前位置的左括号还剩几个未匹配
        // layer表示当前序列中的最大深度
        int left = 0, layer = 0;
        for(int i = 0; i < seq.length(); i++) {
            if(seq[i] == '(') left++;
            else left--;
            layer = max(layer, left);
            if(left == 0) {
                rec.push_back(layer);
                layer = 0;
            }
        }
        // 给每个括号序列剥壳，每一个剥一半的深度给A, 剩下的给B
        // 所以是当当前深度(左括号剩余数)小于等于一般时，该位置是0，否则为1
        // 因为我设置的当匹配到')'时，先Left--,所以判断时是小于一半
        vector<int> ans;
        int pos = 0;
        for(int i = 0; i < seq.length(); i++) {
            if(seq[i] == '(') {
                left++;
                // 遇到左括号，深度小于等于一半
                if(left <= (rec[pos] >> 1)) ans.push_back(0);
                else ans.push_back(1);
            }
            else {
                left--;
                // 遇到右括号，深度小于一半(因为我先将深度减1了)
                if(left < (rec[pos] >> 1)) ans.push_back(0);
                else ans.push_back(1);
            }
            // 当前序列已经走完，去下一个序列
            if(left == 0) {
                pos++;
            }
        }
        return ans;
    }
};
```