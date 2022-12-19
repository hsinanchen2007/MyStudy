### 执行时间
![图片.png](https://pic.leetcode-cn.com/e8a8412618ea79cd52d878fc9a8fa43ac07ca5491feca469726c6d4d0fd3a97d-%E5%9B%BE%E7%89%87.png)

### 分析
这道题跟 [面试题 01.06. 字符串压缩](https://leetcode-cn.com/problems/compress-string-lcci/) 还是不太一样。
一个是要考虑原地修改，另外一个，隐含的题意其实是不一样的。  
这道题支持部分压缩，如下面这个用例：
```
输入：
["a","a","a","a","b","c"]
输出：4

解释：
返回长度 4 ，数组的前 4 个字符应该是：["a", "4", "b", "c"]
```

### 思路
1. 设置 `i` 为遍历指针
2. 设置 `j` 为写入指针
3. 当 `chars[i] == chars[j]` 时，说明字符一样，`cnt++` 计数增加
4. 当不等时，需要
    41. `j++` 把写入指针移到之后一个位置，准备写入数字
    42. 写入数字，注意考虑次数超过 1 位数的情况
    43. `chars[j] = chars[i]` 将填入数字之后的下一位等于下一个要压缩的字符
    44. 通过一些技巧处理，可以将逻辑写在一个循环里
5. 返回写入指针最后的位置 `return j;` 

### 图解
![图片.png](https://pic.leetcode-cn.com/378cfa7330e134dd47f5b1a78630d45dbf42d3dde360223149a4844683b5c0f7-%E5%9B%BE%E7%89%87.png)


### 答题
```C++ []
int compress(vector<char>& chars) 
{
    if (chars.empty()) return 0;
        
    size_t j = 0;
    int cnt = 0;
    for (size_t i = 1; i <= chars.size(); i++)
    {
        cnt++;
        if (i == chars.size() || chars[i] != chars[j])
        {
            j++;
            if (cnt != 1)
            {
                string scnt = to_string(cnt);
                for (auto c : scnt)
                {
                    chars[j++] = c;
                }
            }

            if (i == chars.size()) break;
            chars[j] = chars[i];
            cnt = 0;
        }
    }

    return j;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

