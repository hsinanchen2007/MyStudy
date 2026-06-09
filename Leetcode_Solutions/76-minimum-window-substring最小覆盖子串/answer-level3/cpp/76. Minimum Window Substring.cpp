### 一个错误的尝试
没有pass, 使用索引作为键值，无法处理T中重复字母的情况。

```
class Solution {
public:
    Solution() {
        minwindowLength = 0xFFFF;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> smap;
        int start = 0;
        int end = 0;
        for(auto c : t){
            smap.insert(make_pair<char&,int>(c,-1));
         }
        for(int i = 0; i < s.size(); i++){
            if(smap.find(s[i]) != smap.end()){
                smap.find(s[i])->second = i;
                //smap.insert(make_pair<char, int>(s[i], i));
                update_minIndexRange(smap, start, end);
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    void update_minIndexRange(unordered_map<char,int> smap, int& start, int& end){
        vector<int> windowIdx;
        int windowLength = 0;
        for(auto& pair : smap){
            if(pair.second == -1){
                return;
            } 
            else
            {
                windowIdx.push_back(pair.second);
            }
        }
            sort(windowIdx.begin(), windowIdx.end());
            windowLength = windowIdx.back() - windowIdx.front();
            if(windowLength < minwindowLength){
                minwindowLength = windowLength;
                start = windowIdx.front();
                end = windowIdx.back(); 
            }
        }
    int minwindowLength;
};
```

### 解题思路
滑动窗口，两个map。

### 代码

```cpp
class Solution {
public:
    Solution() {
        minwindowLength = 0xFFFF;
    }
    string minWindow(string s, string t) {
        //tmap 存储t的信息，出现相同字母情况下累加字母的键值
        unordered_map<char,int> tmap;
        //windowMap 存储s的信息，出现相同字母情况下累加字母的键值,当某个字母的键值和tmap匹配上时，就更新matched.
        unordered_map<char,int> windowMap;
        int l = 0;
        int r = 0;
        int minStart = 0;
        int matched = 0;//tmap里面有多少个字母的计数已经完全匹配到了windowMap
        for(auto c : t){
            if(tmap.find(c) == tmap.end()){
                tmap[c] = 1;
            }
            else if(tmap.find(c) != tmap.end()){
                ++tmap[c];
            }
        }
        int unique = tmap.size();//记录一共有多少个字母需要匹配

        while(l <= r && r < s.size()){
            if(tmap.find(s[r]) != tmap.end()){
                if(windowMap.find(s[r]) != windowMap.end()){
                    windowMap[s[r]]++;
                }
                else{
                    windowMap[s[r]] = 1;
                }
                if(windowMap[s[r]] == tmap[s[r]]){
                    matched++;
                }
            }
            //完成匹配任务的时候，更新当前的窗长和索引
            //1.[l, r]依然满足条件，l++ 缩短窗长
            //2.[l, r]不满足条件，r++ 寻找下一个满足条件的窗口
            while(matched == unique){
                if(tmap.find(s[l]) != tmap.end()){
                    if(--windowMap[s[l]] < tmap[s[l]]){
                        matched--;
                        if(minwindowLength > r - l + 1){
                            minStart = l;
                            minwindowLength = r - l + 1;
                        }
                    }
                }
                l++;
            }
            r++;
        }
        return minwindowLength == 0xFFFF ? "" : s.substr(minStart, minwindowLength);
    }
    int minwindowLength;
};
```