### 解题思路
关键：设要交换的糖果为a，b。则a，b之间的关系有：
 a=(sumA−sumB)/2+b
 b=(sumB−sumA)/2+a
### 代码

```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        for(int a:A)
            sumA += a;
        for(int b:B)
            sumB += b;
        unordered_map<int,int> map;
        for(int a:A)
            map[a + (sumB - sumA) / 2];//构造一个对应a需要的糖果棒大小的哈希表
        for(int b:B)//遍历B数组，看看B中元素在不在hash表中
            if(map.find(b) != map.end())
                return {(sumA - sumB) / 2 + b, b};
        return {};
    }
};
```