### 解题思路
Woc,竟然击败了91.74的时间和83.05的空间（捂脸）
我还怕MLE
首先，肥肠简单的逆向思维，每当一个元素加入队前，先将最后的元素提到最前
然鹅，用一个同样大小的Vector操作很难受
所以，开一个两倍大小的Vector，搞俩迭代器。
每次提最后一个数/添加数时就把头迭代器往前
然后每添加一个数就把尾迭代器往前
最后把两个迭代器之间的搞起来（包括尾迭代器的元素）
我知道可以用更省内存的方法处理ans，但是我忘了=-=
### 代码

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size()*2);
        int headIterator = ans.size()-2,lastIterator = ans.size()-1; //迭代器
        ans[lastIterator] = deck[deck.size()-1]; //先让最后一个进来
        for(int i = deck.size()-2;i>=0;--i) {
            ans[headIterator] = ans[lastIterator];
            --headIterator;
            ans[headIterator] = deck[i];
            --headIterator;
            ans[lastIterator] = 0;
            --lastIterator;
        }
        vector<int> answer;
        for(int i = headIterator+1;i<=lastIterator;++i)
            answer.push_back(ans[i]);
        return answer;
    }
};
```