### 运行结果

![image.png](https://pic.leetcode-cn.com/1a1e81bd324e59e0badafaf2d3cac7c2535613e3ab98a6dc108130ec50a4bf18-image.png)

![image.png](https://pic.leetcode-cn.com/b296a4fba66cc69aaabf3f4df5994e4c871286aeea34468ea5f17d94d6bf50da-image.png)

![image.png](https://pic.leetcode-cn.com/937a4ee2d4093f400a4dd4712aaf8adb6e99d85842b2f04b7062031c945de203-image.png)

### 解题思路
简单题，遇到空格就替换

### 代码

```C++ []
class Solution
{
public:
    string replaceSpace(string s)
    {
        string res = "";
        size_t const len = s.size();
        for (size_t i = 0; i < len; i++)
            if (s[i] == ' ')
                res += "%20";
            else
                res += s[i];

        return res;
    }
};
```
```Rust []
impl Solution {
    pub fn replace_space(s: String) -> String {
        // return s.replace(" ", "%20"); // 自带函数，一行
        let mut ans = String::from("");
        for ch in s.as_str().chars() {
            if ch == ' ' {
                ans += "%20";
            } else {
                ans.insert(ans.len(), ch);
            }
        }
        return ans;
    }
}
```
```Go []
func replaceSpace(s string) string {
	var ans string
	for i := 0; i < len(s); i++ {
		if ' ' == s[i] {
			ans += "%20"
		} else {
			ans += string(s[i])
		}
	}
	return ans
}
```

