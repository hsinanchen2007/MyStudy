### 解题思路
我想到的是逆排，我的贪心思路就是先可着大的来。ᕦ(･ㅂ･)ᕤ
我也想问下，这样的效率和题目优解的效率有质的差别么？？？
### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());//逆序排序（由大到小）
        sort(s.rbegin(), s.rend());
        int i = 0;//饼干下标(s[i])
        int j = 0;//孩子下标(g[j])
        int num = 0;
        while(i<s.size() && j<g.size()){
            if(s[i] >= g[j]){
                num++;
                i++;
            }         
            j++;         
        }
        return num;
    }
};
```