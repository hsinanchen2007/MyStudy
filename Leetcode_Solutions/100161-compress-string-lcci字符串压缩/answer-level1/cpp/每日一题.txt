### 解题思路
要实现对字符串压缩就是需要根据当前有几个字符是连续一样的统计一样的数据即可
### 注意
- 通过设置j = i+1搜索与S[i]相同的数据
- 相同的个数即为所压缩的值
- 维持j与i的指针游标即可确定O(n)内执行完毕

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        // O(n)时间复杂度
        int len = S.size();
        string rst;
        for(int i=0; i<len;)
        {
            rst += S[i]; 
            int j = i; ++j;
            int max_circle = 1;
            while(j<len && S[i] == S[j]) {++max_circle;++j;}
            rst += to_string(max_circle);
            if(j==len) break;
            i = j;
        }
        int len_zip = rst.size();
        return len_zip < len ? rst : S;
    }
};
```