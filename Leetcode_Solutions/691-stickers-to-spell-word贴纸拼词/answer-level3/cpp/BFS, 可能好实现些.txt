BFS的实现, 将目标串一次一次裁剪, 裁剪到空后, 返回裁剪的次数

```
class Solution {
public:
    vector<map<char, int>> canStickers;  // 每个词条的字母及对应的个数表
    unorderd_map<string, int> strMinNumMap;   // 特定单词的拼接次数表

    int minStickers(vector<string>& stickers, string target)
    {
        if (target.empty()) {
            return 0;
        }
        if (stickers.empty()) {
            return -1;
        }
        for (auto& stick : stickers) {
            map<char, int> charAndNum;
            for (auto c : stick) {
                charAndNum[c]++;
            }
            if (!charAndNum.empty()) {
                canStickers.push_back(charAndNum);
            }
        }
        if (canStickers.empty()) {
            return -1;
        }

        strMinNumMap[target] = 0;  //初始化目标字符串的拼接次数为0
        queue<string> checkStrQue;
        checkStrQue.push(target);
        while (!checkStrQue.empty()) {
            string curTar = checkStrQue.front();
            checkStrQue.pop();

            map<char, int> tmptar;
            for (auto c : curTar) {  // 构建一个临时的字符及其个数表, 用以裁剪(反向拼接)
                tmptar[c]++;
            }

            for (auto &charAndNum : canStickers) {
                if (charAndNum[tmptar.begin()->first] == 0) {  // 排序后的tar的第一个字母如果不在词条里, 则尝试其他词条
                    continue;
                }
                string newTar = RebuildStr(tmptar, charAndNum); // 将tar按每个词条交集字母裁剪
                if (strMinNumMap.count(newTar) > 0) { // 裁剪后的字串已经处理过, 忽略
                    continue;
                }
                strMinNumMap[newTar] = strMinNumMap[curTar] + 1;
                if (newTar.empty()) {  //新串为空, 说明完全被裁剪, 反向说明完全拼接. return此时的num数即最小值
                    return strMinNumMap[newTar];
                }
                checkStrQue.push(newTar);  //否则继续进行下一次裁剪处理
            }
        }

        return -1;
    }

    string RebuildStr(map<char, int> src, map<char, int>& charAndNum)
    {
        map<char, int>::iterator it;
        string rst;
        for (it = src.begin(); it != src.end(); it++) {
            //if (charAndNum.count(it->first) > 0) {
                it->second -= charAndNum[it->first];
            //}
            if (it->second > 0) {
                rst += string(it->second, it->first);
            }
        }
        return rst;
    }
};
```