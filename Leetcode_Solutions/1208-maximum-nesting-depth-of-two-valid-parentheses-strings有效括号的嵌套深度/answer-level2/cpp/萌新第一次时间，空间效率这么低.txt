### 成果
![image-20200406141446841.png](https://pic.leetcode-cn.com/1e51b86a264bedd9baf5c86567d77de9c85663ee3b060f46517b03af2836928c-image-20200406141446841.png)

### 思路
1. 用两个int变量cnta, cntb分别表示分配给字符串A，B的左括号数量
2. 初始默认全部分配给字符串B，以1填充ans
3. O(n) 遍历整个字符串
    + 遇到左括号
        + cnta <= cntb, 说明A串的左括号数量比B串少(相等)，此左括号分配给A更优, ++cnta
        + cnta > cntb, 说明B串的左括号数量比A串少(相等)，此左括号分配给B更优, ++cntb
    + 遇到右括号
        + cnta >= cntb, 说明A串的左括号数量比B串多(相等), 此右括号分配给A更优, --cnta
        + cnta < cntb, 说明B串的左括号数量比A串多(相等), 此右括号分配给B更优, --cntb
    + 按照如上分配实际就是做相邻分配，能保证A的深度最多只比B深一层。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = (int)seq.size();
        vector<int>ans(n, 1);
        int cnta = 0, cntb = 0;
        for(int i = 0; i < n; ++i){
            if(seq[i] == '('){
                if(cnta <= cntb){
                    ++cnta;
                    ans[i] = 0;
                }else{
                    ++cntb;
                }
            }else{
                if(cnta >= cntb){
                    --cnta;
                    ans[i] = 0;
                }else{
                    --cntb;
                }
            }
        }
        return ans;
    }
};
```