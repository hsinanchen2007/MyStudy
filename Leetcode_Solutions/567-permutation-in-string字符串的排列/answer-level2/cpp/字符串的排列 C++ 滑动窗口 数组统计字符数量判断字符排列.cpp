### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 给定两个字符串s1和s2，写一个函数来判断s2是否包含s1的排列。换句话说，第一个字符串的排列之一是第二个字符串的子串。
    // 解法：滑动窗口。每次s2中截取和s1等长的字符串，与s1进行比较，利用数组来统计a-z的数量，辅助比较
    bool checkInclusion(string s1, string s2) {
        // n1为s1的长度，n2为s2的长度，left为滑动窗口左边界
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        vector<int> m(128);
        // 遍历s1中的每一个字符，m中保存s1中的每一个字符的个数。
        for(char c: s1) m[c]++;
        // 扫描s2[right]
        for(int right = 0; right < n2; right++) {
            // 当s2[right]在m中计数值为0时，计数值在此循环中会经历一次减减和一次加加，left加1，然后进入下一个循环的right加1
            // 当s2[right]在m中计数值不为0时，在m中该字符对应的个数会经历一次减减，left不变，判断是否符合滑动窗口right-left+1==n1，不符合则right在下一个循环加1，窗口放大1，若下一个循环的s2[right]依然有计数，则继续递减m中s2[right]字符的个数和判断窗口，如此循环扩大窗口至满足条件，此时m中保存的个数刚好全减到0。如果扩大到下一个循环的s2[right]为0还不满足right-left+1==n1，则进入while循环。left递增并将之前m中减小的计数递加回来。
            if (--m[s2[right]] < 0) {
                while(++m[s2[left++]] != 0){}
            }
            else if (right - left + 1 == n1) {
                return true;
            }
        }
        return n1 == 0;
    }
};


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size(), left = 0;
    vector<int> m(128);
    for(char c: s1) m[c]++;
    for(int right = 0; right < n2; right++) {
        if (--m[s2[right]] < 0) {
            while(++m[s2[left++]] != 0){}
        }
        else if (right - left + 1 == n1) {
            return true;
        }
    }
    return n1 == 0;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    if (checkInclusion(s1, s2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}

```