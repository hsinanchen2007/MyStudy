# c++ 回溯(DFS) 8ms

# 思路
1. 需要一个函数用于回溯: hand(一共n个球)中的任意球往board(一共m个球)的**任意**位置插入, 那么时间复杂度=O(n!)*O(m!)
2. 需要一个函数用于(迭代式)消除连续的球，每次插入新的球后调用这个函数
3. 但是这样会超时, 所以需要大量的剪枝，具体的思路见代码:)

# 测试用例举例: (括号内是插入的球)
1. 一般难度的: board: WWRRBBWW, hand:WWRB, 
   WWRRBBWW->WWRR(R)BBWW->WWBB(B)WW->WWWW->"", 结果为***2***
2. 容易WA的: board: RRWWRRBBRR, hand: WB: 看起来没有解(-1), **但正确结果是2**: 
   **正确流程为**RRWWRRBBRR->RRWWRRBBR(W)R->RRWWRRBB(B)R(W)R->RRWWRRR(W)R->RRWW(W)R->RRR->""

   部分**题解：限制插入球位置在board相同类型球后面将会WA, 输出-1, 不能作此剪枝**
   但是**又有部分题解尽管作出限制, 但AC**, 根据我的理解, **这些题解在插入球满足连续>=3个球相同时同时DFS/BFS了立即消去球和没有立即消去球的情况**, 不符合祖玛题意但结果正确，出现了如下流程: RRWWRRBBRR->RRWW(W)RRBBRR->RRRRBBRR->RRRRBB(B)RR->RRRRRR->""
3. 容易TLE的,球的种类多: board: WBGGRRYYR, hand: BBYRGWW, 流程应当为 WBGGRRYYR->WBGGRRYY(Y)R->WBGGRRR->WBGG(G)->WB->W(WW)B->B(BB)->"", 如何解决TLE请参加我代码中的剪枝:), 结果是***6***


# **代码**  4-12ms
```cpp
//带大量剪枝的回溯, 代码注释中的"字符"与我的题解中的"球"为同一个意思

class Solution {
private:
    int gblRes;
    /*
     * 从下标i开始迭代式消除s, 参考:https://leetcode-cn.com/problems/zuma-game/solution/c-hui-su-fa-by-da-li-wang-3/
     */
    string boom(string s, int i) {
        if (s.empty()) return "";
        int left = i, right = i;
        while (left > 0 && s[left - 1] == s[left]) --left;
        while (right < s.size() - 1 && s[right + 1] == s[right]) ++right;
        if (right - left + 1 >= 3) {
            s = s.substr(0, left) + s.substr(right + 1);
            return boom(s, max(left - 1, 0));
        }
        return s;
    }

    /*
     * pB:当前board, handCount:当前hand字符统计数量, usedCount:已用字符数量, remainCount:剩余字符数量
     */
    void DFS(string pB, map<char, int>& handCount, int usedCount, int remainCount) {
        if (pB.empty()) gblRes = min(gblRes, usedCount);
        else {
            if ((remainCount == 0) || (usedCount + 1) >= gblRes) {  //没有字符了, 或者不可能再回溯出更小的消除路径了, 剪枝
                return;
            }
            else {
                //计算接下来至少要的字符数量
                map<char, int> pBcount;
                for (const auto& pc : pB) pBcount[pc]++;
                int nextAtLeastCount = 0;

                for (auto& p : pBcount) {
                    if (p.second < 3) {
                        nextAtLeastCount += 3 - p.second;
                    }
                    if ((3 - p.second) > handCount[p.first]) //mhand的某个字符数量不够, 剪枝
                        return;
                }
                if ((nextAtLeastCount + usedCount) >= gblRes) {  //不可能再回溯出更小的消除路径了, 剪枝, 这是个关键剪枝: 如果已经得到了某个解, 当前再搜索下去不可能比它更小则停止此路线搜索!, 此处可以在相当浅的递归中return
                    return;
                }

                //开始迭代
                string temps;
                for (auto& h : handCount) {
                    if (h.second == 0) continue;  //mhand某个字符没了, 跳过
                    char choose = h.first;
                    if (pBcount.find(choose) == pBcount.end()) continue;   //pB没有choose符号, 跳过
                    for (int index = 0; index < pB.size(); ++index) {    //
                        if (index > 0 && choose == pB[index - 1])
                            continue;  //当前球和board上此球准备的插入位置前的球颜色一样, 已有相同情况讨论, 跳过
                        temps = pB;
                        temps.insert(temps.begin() + index, choose);
                        temps = this->boom(temps, index);
                        handCount[choose]--;
                        DFS(temps, handCount, usedCount + 1, remainCount - 1);
                        handCount[choose]++;
                    }

                    //试图往pB最后插
                    if (choose == pB.back())
                        continue;  //当前球和board上此球准备的插入位置前的球颜色一样, 已有相同情况讨论, 跳过
                    temps = pB;
                    temps.push_back(choose);
                    //不需要调用boom, 因为一定不会boom!
                    handCount[choose]--;
                    DFS(temps, handCount, usedCount + 1, remainCount - 1);
                    handCount[choose]++;
                }

            }
        }

    }
public:
    int findMinStep(string board, string hand) {
        gblRes = INT_MAX;
        map<char, int> handCount; //统计hand字符数量
        for (const auto& h : hand) handCount[h]++;

        DFS(board, handCount, 0, hand.size());
        return (gblRes == INT_MAX) ? -1 : gblRes;
    }
};
```

**非常感谢您阅读到这里，欢迎批评指正！**