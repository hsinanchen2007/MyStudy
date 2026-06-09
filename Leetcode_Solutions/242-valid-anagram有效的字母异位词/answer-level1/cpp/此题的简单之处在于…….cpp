此题的简单之处在于，可以使用sort将两个string类型排序，这样，根据其排序后的状态便可知是否为字母异位词

具体实现如下：

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        return false;
    }
};

```