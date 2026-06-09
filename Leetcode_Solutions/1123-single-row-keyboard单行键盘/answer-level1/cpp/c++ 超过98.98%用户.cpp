![image.png](https://pic.leetcode-cn.com/9784fbdbef256b6b0b48555be558f0324316c72bc00e000c0167a02543f363bc-image.png)
这个问题的难度并不高，使用哈希表可以轻松解决，但是STL库中的map底层数据结构为红黑树，有序，不重复。
使用map有些多余，杀鸡不用宰牛刀，我们不如自己建立一个长度为26的数组简单明了！！！
下面请看代码
```
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res=0,pre,cur=0;
        int arr[26];
        for(int i=0;i<26;i++)  arr[keyboard[i]-'a']=i;  //记录各个字母在keyboard的下标
        for(auto&ch:word){//遍历word
            pre=cur;
            cur=arr[ch-'a'];
            res+=abs(pre-cur);
        }
        return res;
    }
};
```
