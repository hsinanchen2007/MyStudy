### 解题思路
一次遍历+跳重
- 添加字符
- 跳过重复元素并且计数
- 利用`std::to_string()`函数将整数转化为`string`类型，并添加

最终返回值按照要求判断，如果`res`的长度小于元字符创`S`长度，返回`res`，否则返回`S`.

结果和代码如下：
![lc字符串压缩.PNG](https://pic.leetcode-cn.com/b80f27b77aa48e3f86ca4a7406338156b2667e956ed277d14b6ac1b80532881f-lc%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8E%8B%E7%BC%A9.PNG)


### 代码

```cpp
/*
** 这个涉及到c++字符串拼接的问题，s = s + 'A'会产生一个新的对象;
** 在返回结果给s，s += 'A'应该是涉及到对象的引用，不需要产生额外的对象。
** 因此s = s + 'A'在每次拼接时都产生额外的对象占用内存。
** 在字符串特别长的时候（例如本题的最后一个测试用例）会导致超出内存限制的问题
*/
class Solution {
public:
    string compressString(string S) {
        string res;
        for(int i=0;i<S.size();i++)
        {
            int nums=1;
            res.push_back(S[i]);
            while((i+1)<S.size() && (S[i]==S[i+1])) // 跳过重复元素，注意这里是向后判断
            {
                nums++;
                i++;
            }
            res+=to_string(nums);
        }
        return (res.size()<S.size())? res:S;
    }
};
```