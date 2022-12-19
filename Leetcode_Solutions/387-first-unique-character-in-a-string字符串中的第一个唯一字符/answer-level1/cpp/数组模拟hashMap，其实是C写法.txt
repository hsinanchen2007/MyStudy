### 刚转cpp，STL还比较陌生，索性用数组速度也更快些。题目本身简单，看注释吧，比较完整

此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/fd5aabd82d37f55ddef987f34f2ef1862652b45dea7fdc1978550db27d128c90-image.png)

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        // 题意表明，字符是否重复跟顺序无关，因此先以O(N)遍历所有字符，统计对应 字符 出现频率
        // 由于字符串 s 长度未知，但 26 个字母，可以只开 26的int[] 数组
        int arrCnt[26] = {0} ;
        for(auto cha : s) {
            arrCnt[cha - 'a']++;            
        }
        
        // for(auto i=0;i<26;i++) {
        for(int i = 0;i<s.size();i++) {
            if(arrCnt[s[i] - 'a']==1) return i;
        }
        return -1;
    }
};
```