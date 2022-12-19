
核心逻辑：
1. 依照条件 不超过26字符，所以已经使用的字符可以转换为int类型数值的各个位,进行位运算。
2. 依照条件 不超过16个字符串，可以考虑使用递归遍历，不用担心爆仓。
3. 剔除自身含有重复字符的字符串，其他转换为位图，并加入到列表。
4. 对列表进行递归操作，关键元素：
    1，初始条件： 从index=0开始。
    2，重复逻辑： 不让arr[index]参与到结果和让arr[index]参与到结果分别会怎样计算。
                其中结果定义为arr[index+1, last]的最长有效结果。
    3，终止条件： index到达arr[last]终止


```cpp
class Solution {
public:

    int maxLength(vector<string>& arr) {
        const int size = arr.size();
        vector<Bitmap> bitmaps;
        for (auto s : arr) {
            Bitmap bitmap(0,0);
            // string s长度不超过26，所以可以转换为uint类型位图（可容纳32位）。
            if (Str2Bitmap(s, bitmap)) {
                //如果没有重复，将其mask和len计入位图列表。
                bitmaps.push_back(bitmap);
            } /* else {
                // string s内部本身有重复，跟任何其他子串都不能形成有效组合。直接忽略。
            } */
        }
        // 声明一个位图，用于存放最长有效长度以及对应的mask。
        Bitmap result(0,0);
        // 进行dfs深度遍历，从index 0 开始，直到 最后一个数组元素结束。
        return GetMaxLen(bitmaps, 0, result);
    }

    int GetMaxLen(vector<Bitmap> &bitmaps, int index, Bitmap result) {
        // 遍历结束条件
        if (index >= bitmaps.size()) {
            return result.len;
        }
        // maxLen标示[index, last]的有效最大长度（同时也是函数返回值）。 递归计算分为两种情况：
        // case 1, 当前字符串不加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果一致。
        int maxLen = GetMaxLen(bitmaps, index + 1, result);
        // case 2， 当前字符串加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果是否一致需要分两种情况：
        if ((result.mask & (bitmaps[index].mask)) == 0) {
            // case 2.1 如果当前字符串与结果字符串不重复： 说明是有效的，需要刷新后继续Dfs遍历。
            // 做法： 将当前字符串的len和mask更新到结果中。
            result.mask |= bitmaps[index].mask;
            result.len += bitmaps[index].len;
            // 调用Dfs获取当前结果与与[index+1, last]各元素最长的有效组合 长度lenWithCur
            int lenWithCur = GetMaxLen(bitmaps, index + 1, result);
            // 如果结果中加入当前字符(arr[index])比不加入结果的情况更好(lenWithCur > maxLen),则更新返回值maxLen。
            if (lenWithCur > maxLen) {
                maxLen = lenWithCur;
            }
        } /* else {
            // case 2.2 如果加入当前字符串arr[index]与已经结果result.mask有重复：
            // 说明结果是无效的， 无需再深入遍历了。
        } */
        return maxLen;
    }


```



完整实现：
```cpp
using namespace std;

enum {
    MAX_LETTER = 26,
};

struct Bitmap{
    unsigned int mask;
    int len;
    Bitmap(int m, int l) {
        mask = m;
        len = l;
    }
};

class Solution {
// class Solution {
public:

    int maxLength(vector<string>& arr) {
        const int size = arr.size();
        vector<Bitmap> bitmaps;
        for (auto s : arr) {
            Bitmap bitmap(0,0);
            // string s长度不超过26，所以可以转换为uint类型位图（可容纳32位）。
            if (Str2Bitmap(s, bitmap)) {
                //如果没有重复，将其mask和len计入位图列表。
                bitmaps.push_back(bitmap);
            } /* else {
                // string s内部本身有重复，跟任何其他子串都不能形成有效组合。直接忽略。
            } */
        }
        // 声明一个位图，用于存放最长有效长度以及对应的mask。
        Bitmap result(0,0);
        // 进行dfs深度遍历，从index 0 开始，直到 最后一个数组元素结束。
        return GetMaxLen(bitmaps, 0, result);
    }

    int GetMaxLen(vector<Bitmap> &bitmaps, int index, Bitmap result) {
        // 遍历结束条件
        if (index >= bitmaps.size()) {
            return result.len;
        }
        // maxLen标示[index, last]的有效最大长度（同时也是函数返回值）。 递归计算分为两种情况：
        // case 1, 当前字符串不加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果一致。
        int maxLen = GetMaxLen(bitmaps, index + 1, result);
        // case 2， 当前字符串加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果是否一致需要分两种情况：
        if ((result.mask & (bitmaps[index].mask)) == 0) {
            // case 2.1 如果当前字符串与结果字符串不重复： 说明是有效的，需要刷新后继续Dfs遍历。
            // 做法： 将当前字符串的len和mask更新到结果中。
            result.mask |= bitmaps[index].mask;
            result.len += bitmaps[index].len;
            // 调用Dfs获取当前结果与与[index+1, last]各元素最长的有效组合 长度lenWithCur
            int lenWithCur = GetMaxLen(bitmaps, index + 1, result);
            // 如果结果中加入当前字符(arr[index])比不加入结果的情况更好(lenWithCur > maxLen),则更新返回值maxLen。
            if (lenWithCur > maxLen) {
                maxLen = lenWithCur;
            }
        } /* else {
            // case 2.2 如果加入当前字符串arr[index]与已经结果result.mask有重复：
            // 说明结果是无效的， 无需再深入遍历了。
        } */
        return maxLen;
    }

    bool Str2Bitmap(string &s, Bitmap &bitmap) {
        unsigned int ret = 0;
        for (auto c : s) {
            unsigned int mask = 1 << (c-'a');
            if (mask & ret) {
                return false;
            }
            ret |= mask;
        }
        bitmap.mask = ret;
        bitmap.len = s.size();
        return true;
    }
};

```
