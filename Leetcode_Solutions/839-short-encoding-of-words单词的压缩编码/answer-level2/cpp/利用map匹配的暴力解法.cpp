### 解题思路
第一次遇到这种情况，暴力解法，虽然不给过但是自己觉得能过，不信邪提交了三次，虽然没抱什么期望，但是第三次竟然给过了
~~我不要你觉得我要我觉得~~
![QQ截图20200328211159.png](https://pic.leetcode-cn.com/fb9dd8a969a9dffd9e7e092b88dae85412adae0e1e5ee08e5b74692bda624c64-QQ%E6%88%AA%E5%9B%BE20200328211159.png)
具体思路就是每进来一个字符串就与map中现存的所有节点进行字符串比对（从尾到头）一旦有包含关系就用长的字符串替换点原比对节点。
map中相当于键值存储的是最精简字符串集合，值存储的是对应键值字符段的长度。
最后遍历一遍关联容器中所有长度加和（每次还要加1，因为#的存在），就是答案啦。
### 代码

```cpp
class Solution {
public:
    string CompareWords(string a, string b) {
        int Aend = a.size() - 1;
        int Bend = b.size() - 1;
        while (Aend != -1 && Bend != -1) {
            if (a[Aend] != b[Bend]) return "";
            Aend--;
            Bend--;
        }
        if (a.size() > b.size())return a;
        return b;
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> m;
        unordered_map<string, int>::iterator iter;
        m[words[0]] = words[0].size();
        for (int i = 1; i < words.size(); i++) {
            iter = m.begin();
            while (iter != m.end()) {
                if (iter->first[iter->first.size() - 1] != words[i][words[i].size() - 1]) iter++;
                else{
                    string temp = CompareWords(iter->first, words[i]);
                    if (temp == "") iter++;
                    else {
                        m.erase(iter);
                        m[temp] = temp.size();
                        break;
                    }  
                } 
            }
            if(iter==m.end()) m[words[i]] = words[i].size();
        }
        iter = m.begin();
        int ans = 0;
        while (iter != m.end()) {
            ans += (iter->second + 1);
            iter++;
        }
        return ans;
    }
};
```