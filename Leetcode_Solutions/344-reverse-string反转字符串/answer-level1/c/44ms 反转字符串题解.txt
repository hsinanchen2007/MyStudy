### 解题思路
执行用时 :44 ms, 在所有 cpp 提交中击败了99.57%的用户
内存消耗 :15.2 MB, 在所有 cpp 提交中击败了77.96%的用户

这是本蒟蒻的第一篇题解
其实这道题可以直接用暴力水过，但是因为没有考虑领扣输入的特异性，导致忘记判断是否空输入，导致第一次直接出错：
![360截图20191210213704899.jpg](https://pic.leetcode-cn.com/373997db13ba4bacfe47d34ebcb411dbf2ee8e958d370a85e8c3a6c3b2127420-360%E6%88%AA%E5%9B%BE20191210213704899.jpg)
后来我发现了这个，及时的修正了过来。
![360截图20191210213825665.jpg](https://pic.leetcode-cn.com/4a38e2f38eefffe484a682a58618e4955de3473ee1aa55a0fa3ceb142cf3d41f-360%E6%88%AA%E5%9B%BE20191210213825665.jpg)
就在这个时候，我看到了某位大佬的[题解](https://leetcode-cn.com/problems/reverse-string/solution/shuang-zhi-zhen-by-1050669722/)，然后我就思考，能否也让我的代码运行速度加快。
于是我看了一下第二个示例，发现如果碰到这种情况，特判一下可以省掉不少的时间，于是我就尝试了一下，然后：
![360截图20191210214102510.jpg](https://pic.leetcode-cn.com/e40c6e22f47d41fe053694a43b967fe8de497cd9a547faa74dfc6bffc958ae71-360%E6%88%AA%E5%9B%BE20191210214102510.jpg)



### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;//判空输入
        int l=s.size()-1,k=l/2;
        char ch;
        for (int i=0; i <= k; i++) {
            if(s[l-i] == s[i]) continue;//判相同，对节省时间非常有帮助
            ch=s[l-i];
            s[l-i]=s[i];
            s[i]=ch;
            //调换位置
        }
    }
};
```