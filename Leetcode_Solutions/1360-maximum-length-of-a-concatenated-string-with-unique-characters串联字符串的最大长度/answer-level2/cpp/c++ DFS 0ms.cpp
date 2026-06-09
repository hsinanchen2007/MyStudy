![image.png](https://pic.leetcode-cn.com/df04aafdc59ab46cabad9bfa955c7280d0e69acc6cdacce5f561d0e7c32f5475-image.png)


代码应该还算比较简洁
逻辑
1.判断是否可以插入当前位置的字符串
2.如果可以，分两种情况
2.1 插入当前位置的字符串，pos+1，继续递归
2.2 不插入当前位置的字符串，pos+1，继续递归
取其中较大者
3.如果不行，pos+1，继续递归

```
class Solution {
public:
    int maxLength(vector<string>& arr, size_t pos = 0, array<int, 26>& records = const_cast<array<int, 26>&>(records_))
    {
        if (arr.size() == pos) {
            return 0;
        }

        auto temp = records;
        if (isAllowInsert(arr[pos], temp)) {
            return max(maxLength(arr, pos + 1, records), static_cast<int>(arr[pos].size() + maxLength(arr, pos + 1, temp)));
        }
        return maxLength(arr, pos + 1, records);
    }

private:
    bool isAllowInsert(const string& str, array<int, 26>& records) {
        for (auto ch : str) {
            if (records[ch - 'a']++) {
                return false;
            }
        }
        return true;
    }

    static constexpr array<int, 26> records_ = array<int, 26>();
};
```
