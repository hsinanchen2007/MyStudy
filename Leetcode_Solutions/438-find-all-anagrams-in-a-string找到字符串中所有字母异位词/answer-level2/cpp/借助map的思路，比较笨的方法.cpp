### 解题思路

笨方法：
第一步：先将p放到map中
第二步：循环得到p字串长度的tempM，比较m和tempM是否相等即可
情况1：
m和tempM相等说明，找到一个符合要求的异位字符子串，同时移动一个位置继续扫描
此处需要济注意到，如果起始位置的字母对应1个以上字母时，减掉一个即可，不能erase掉
情况2：
m和tempM不相等又有二种情况：
case 1：最后加入到tempM中的s[i]在m中，说明不可以直接跳过，只能移动一个位置继续扫描
此处需要济注意到，如果起始位置的字母对应1个以上字母时，减掉一个即可，不能erase掉
case 2：最后加入到tempM中的s[i]不在m中，可以直接忽略所有的重新开始构建tempM  

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lenS = s.length();
        int lenP = p.length();
        // printf("lenP=%d, lenS=%d\n", lenP, lenS);
        // 第一步：先将p放到map中
        map<char, int> m;
        for (int i = 0; i < lenP; i ++) {
            ++m[p[i]];
        }
        // 第二步：循环得到p字串长度的tempM，比较m和tempM是否相等即可
        map<char, int> tempM;
        int count = 0;
        for (int i = 0; i < lenS; i++) {
            ++tempM[s[i]];
            count++;
            if (count == lenP) {
                // printf("count=%d, i=%d, i-lenP+1=%d\n", count, i, i-lenP+1);
                if (m == tempM) {
                    // printf("equal case\n");
                    // m和tempM相等说明，找到一个符合要求的异位字符子串，同时移动一个位置继续扫描
                    // 此处需要济注意到，如果起始位置的字母对应1个以上字母时，减掉一个即可，不能erase掉
                    int startPos = i-lenP+1;
                    res.push_back(startPos);
                    if (tempM[s[startPos]] == 1) {
                        tempM.erase(s[startPos]);
                    } else {
                        --tempM[s[startPos]];
                    }
                    count--;
                } else {
                    // printf("not equal case\n");
                    // m和tempM不相等有二种情况：                    
                    map<char,int>::iterator it = m.find(s[i]);
                    if (it != m.end()) {
                        // case 1：最后加入到tempM中的s[i]在m中，说明不可以直接跳过，只能移动一个位置继续扫描
                        // 此处需要济注意到，如果起始位置的字母对应1个以上字母时，减掉一个即可，不能erase掉
                        int startPos = i-lenP+1;
                        if (tempM[s[startPos]] == 1) {
                            tempM.erase(s[startPos]);
                        } else {
                            --tempM[s[startPos]];
                        }
                        count--;
                    } else {   
                        // case 2：最后加入到tempM中的s[i]不在m中，可以直接忽略所有的重新开始构建tempM     
                        tempM.clear();
                        count = 0;
                    }
                }
            }
        }
        return res;
    }
    // 判断二个map变量是否相等，其实也可直接用if (mapSrc == mapDst)
    bool isSameMap(map<char, int>& mapSrc, map<char, int>& mapDst) {
        // printf("mapSrc.size()=%d, mapDst.size()=%d\n", mapSrc.size(), mapDst.size());
        // for (auto m : mapSrc) {
        //     printf("in mapSrc -> m.first=%c, m.second=%d\n", m.first, m.second);
        // }
        // for (auto m : mapDst) {
        //     printf("in mapDst -> m.first=%c, m.second=%d\n", m.first, m.second);
        // }
        if ( mapSrc.size() != mapDst.size() ) {
            // printf("return false 1\n");
            return false;
        }
        map<char,int>::iterator it = mapSrc.begin();
        while( it != mapSrc.end()) {
            map<char,int>::iterator itDst = mapDst.find(it->first);
            if (itDst != mapDst.end()) {
                if (itDst->second != it->second) {
                    // printf("return false 2\n");
                    return false;
                }
            } else {
                // printf("return false 3\n");
                return false;
            }
            it++;
        }
        // printf("return true\n");
        return true;
    }
};
```