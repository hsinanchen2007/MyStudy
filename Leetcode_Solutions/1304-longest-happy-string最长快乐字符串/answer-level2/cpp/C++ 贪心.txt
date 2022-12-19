### 解题思路
本题只要一个可行解，可以用贪心策略做

- 用ans记录当前字符串，初始化为“”，a/b/c表示剩余可以使用的a/b/c的数量
- 每一步肯定是选取可以加在ans后面的、且剩余最多的字符加在后面，可选的加入数量为1/2
    - 如果当前要加的字符是所有字符里数量最多的，且剩余数量大于2，则直接加2个在ans后面，因为它数量多，要尽可能的“浪费“
    - 如果当前要加的字符不是所有字符里数量最多的，则只能加1个，因为当前字符起到的作用是”隔板“，用来分隔剩的最多的那个字符，需要省着点用. 例如, a=3, c=11，答案为ccaccaccacc，a作为隔板每次只加一个，才能引入更多的c


### 代码

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        map<int, vector<char>, greater<int>> m;//升序记录各字符的剩余数量
        if(a > 0)
            m[a].push_back('a');
        if(b > 0)
            m[b].push_back('b');
        if(c > 0)
            m[c].push_back('c');
        string ans = "";
        while(1){
            bool f = false;//标识还能不能继续往后面加
            auto it = m.begin();//从剩余数量最多的开始看
            while(!f && it != m.end()){
                int size = it->second.size();
                for(int i = 0; i < size; i++){
                    if(ans == "" || ans.back() != it->second[i]){//可以加在ans后
                        int cnt = it->first;
                        char c = it->second[i];
                        if(cnt >= 2 && it == m.begin()){//加2个
                            ans += c;
                            ans += c;
                            cnt -= 2;
                        }
                        else{//加1个
                            ans += c;
                            cnt -= 1;
                        }
                        if(size == 1)
                            m.erase(it);
                        else
                            it->second.erase(it->second.begin() + i);
                        if(cnt > 0)
                            m[cnt].push_back(c);
                        f = true;
                        break;
                    }
                }
                it++;
            }
            if(!f) break;
        }
        return ans;
    }
};
```