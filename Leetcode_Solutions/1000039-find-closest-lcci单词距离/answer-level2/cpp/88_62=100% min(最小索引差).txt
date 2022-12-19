### 解题思路
先建立一个数组初始化全0。
遍历words：
    如果words[i]的值等于word1的值，那么数组对应的位置赋值为1；
    如果words[i]的值等于word2的值，那么数组对应的位置赋值为2。

最后遍历数组，返回索引值差的最小值即可！


![image.png](https://pic.leetcode-cn.com/61d5e3657a22708f1325c68334523a5639827317ec1f0d52df5b13d9d714b0b4-image.png)

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int arr[words.size()] = {0};
        int res = 0x7fffffff, one = 0x7fffffff, two = 0x7fffffff;
        for(int i = 0; i < words.size(); i++){
            if(words[i]==word1) arr[i]=1;
            if(words[i]==word2) arr[i]=2;
        }
        for(int i = 0; i < words.size(); i++){
            if(arr[i]==1) one = i;
            if(arr[i]==2) two = i;
            if(one!=0x7fffffff && two!=0x7fffffff)
	            res = min(res, abs(one-two));
        }
        return res;
    }
};
```