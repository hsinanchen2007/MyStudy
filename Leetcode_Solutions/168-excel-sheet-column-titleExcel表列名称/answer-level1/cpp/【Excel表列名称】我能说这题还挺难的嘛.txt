### 思路
1. WA 了好几次
2. 一开始没想明白到底要怎样 `% 26`
3. 后来亲自打开 `EXCEL` 
4. 拉了好长一排才有点想明白，菜哭

### 图解
![图片.png](https://pic.leetcode-cn.com/72b2a96e1526021c316b8017bbf82a193d4fc5b51d829cd742863eec1964b0b1-%E5%9B%BE%E7%89%87.png)

### 答题
```C++ []
class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans = "";
        while (n > 0)
        {
            n -= 1;
            ans.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

