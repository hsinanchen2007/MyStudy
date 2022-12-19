### 解题思路
拿到这个题，一看这不就是某个周赛题的简化版嘛
捞得嘛不谈
反手开一个数组，表示某一个字母，别问我为啥不同map，就觉得这样很帅
s1++，s2--
只要判断数组中最后有没有非0的，有就false
最后一波双百，多帅哦
芜湖~~起飞
![image.png](https://pic.leetcode-cn.com/ebb955d39b77f6238206f52daf80b03e7ac94890ddce5a29ef2bd315f7b92793-image.png)
### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int>help(26,0);
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 != n2)
            return false;
        for(int i = 0; i < n1;i++){
            help[s1[i]-'a']++;
            help[s2[i]-'a']--;
        }
        for(int i = 0;i < 26;i++){
            if(help[i]!=0)
                return false;
        }
        return true;
    }
};
```