# 滑动窗口算法
一直维护一个可行窗口，取最小那个
# 判断字符都有
哈希表
# 细节看注释


````
//重构代码
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //题目说如果有解， 所以应该res = “” 可能无解
        string res = "";//确保有解，那先假设res = s整串，这样比较size() 小就更新
        unordered_map<char, int> T, window;
        int type = t.size();//假设T每个字符不同
        for (auto i: t) {
            T[i]++;
            if (T[i] > 1) //如果字符出现过 就自减，最后type就是 字符种类数
                type--;
        }
        
        //首先先构造一个可行窗口 
        //然后看看能不能缩
        int satisfy = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            window[s[right]]++;
            if (window[s[right]] == T[s[right]])//个数一样，说明这个字符满足了 不能大于也加 比如satisfy还不够 但某个字符超过所需的 此时不应该satisfy++
                satisfy++;
            
            while (satisfy == type) { //不可行才退出
                if (res == "" || res.size() > right - left + 1)
                    res = s.substr(left, right - left + 1);       
                //left一直滑  直到不可行窗口
                if (T[s[left]] == 0) {//说明这个字符根本不需要 应该跳过 肯定还是可行的此时
                    left++;
                    continue;
                }
                //去到这肯定 这个字符在T中，设字符ch  但注意此时肯定T【ch】>= window【ch】
                window[s[left]]--;
                if (window[s[left]] < T[s[left]]) { //说明这个left是关键的一个，使得不可行了  能去到这就代表需要字符 window 和 T是一样的，所以无需判断window[s[left]]-- 之前 和 T 相等
                    satisfy--;//满足数减1
                }
                left++;
                //当然还有T【ch】> window【ch】 的情况，那就不进这个if 继续循环更新
            }

            // if (satisfy == type) {//够了 说明是一个可行窗口  记录子串
            //     if (res == "" || res.size() > right - left + 1)
            //         res = s.substr(left, right - left + 1);
            //     //现在想能不能缩一下
            //     int done = 1;
            //     while (done) {
            //         if (T[s[left]] == 0) {//说明这个字符根本不需要 应该跳过 不然搞得下面 -1 < 0 满足条件
            //             left++;
            //             if (res == "" || res.size() > right - left + 1)
            //                 res = s.substr(left, right - left + 1);
            //             continue;
            //         }
                    
            //         window[s[left]]--;
            //         if (window[s[left]] < T[s[left]]) { //说明这个left是关键的一个，使得不可行了  能去到这就代表需要字符 window 和 T是一样的，所以无需判断window[s[left]]-- 之前 和 T 相等
            //             satisfy--;//满足数减1
            //             done = 0;
            //         }
            //         else if (res == "" || res.size() > right - left) {
            //             res = s.substr(left + 1, right - left);
            //         }
            //         left++;//left会追上 right吗   一开始【left，right】是可行的  最差情况就是left = right+1 如果此时left越界，right for后++ 也会越界 所以无需判断
            //     }
            // }
        }
        return res;
    }
};
```
