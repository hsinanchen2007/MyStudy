### 解题思路
1.计算出所给序号所在层数
2.利用对称思想
### 代码

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int layer = log(label)/log(2) + 1;   //计算出所给序号所在层数
        vector<int> res(layer, 1);
        while((layer--)>1){
            res[layer]=label;
            label=label/2;
            int l=pow(2,layer-1);
            int r=pow(2,layer)-1;
            label=(r-label)+l;               //对称
        }
        return res;
    }
};
![1104.PNG](https://pic.leetcode-cn.com/aefb9be76f16253d237f67bb15ef7d96509e787ff7a7dcd1c0bb893ea1cbe0aa-1104.PNG)

```