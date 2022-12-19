# 1. 理解
在没有想到滑动窗口前，我尝试使用找规律的方式解决，用偏向数学的方式给出这个题的通解，不是不可行，只是考虑的情况比较多，判断条件也不是很方便。瞄了一眼其他人的题解，便有了滑动窗口的思路。
数字由小到大有序，通过窗口滑动，计算窗口内的数和，定义清楚窗口边界移动的条件，这道题就不难了。
# 2. 思路
1. 定义初始状态，窗口长度为2，包含1和2，窗口内数的和Sw为3，左边界lp，右边界rp。
2. 比较窗口内数的和Sw与目标值S的关系：
    - Sw < s ==> rp += 1,更新Sw
    - Sw = s ==> 得到一组解，lp+=2，rp+=1，更新Sw
    - Sw > s:
        - lp+1!=rp ==> lp+=1，更新Sw
        - lp+1==rp ==> 窗口大小小于2，求解结束#
# 3. 代码
```c++ []
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> sequences;
        vector<int> sequence(target);
        sequence[0] = 1;
        sequence[1] = 2;
        auto lp = sequence.begin(), rp = lp+1;
        int sw = 3;
        while(true){
            *(rp+1) = (*rp)+1;
            if(sw < target){
                sw += *++rp;
            }else if(sw == target){
                vector<int> out(lp, rp+1);
                sequences.push_back(out);
                lp += 2;
                sw -= *(lp-2) + *(lp-1);
                sw += *++rp;
            }else if(lp + 1 != rp){
                sw -= *lp++;
            }else{
                return sequences;
            }
        }
    }
};
```
# 4. 总结
滑动窗口是一种常见的解题思路，已知可解决的问题有：
- 连续正数和
- 最大数队列（结合双端单调队列）