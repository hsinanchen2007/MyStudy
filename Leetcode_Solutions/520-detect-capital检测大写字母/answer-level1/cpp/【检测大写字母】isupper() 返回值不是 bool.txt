### 执行时间
![图片.png](https://pic.leetcode-cn.com/e18320ca8f2dff798e389c69e710d0f39264cd10881dbe6d0ca6ef8680a4b690-%E5%9B%BE%E7%89%87.png)

### 思路
1. 如果单词长度小于 2 ，即 1 个字母，显然怎么搞都是对的
2. 记录第一个字母是否大写
3. 记录第二个字母是否大写
4. 此时，出现第一种错误情况，即第一个字母是小写，第二个字母是大写
5. 然后从第三个字母开始遍历，只需要判断是否与第二个字母的大小写状态相同即可

### 答题
```C++ []
bool detectCapitalUse(string word)
{
    if (word.size() < 2) return true;
    bool flag_first = isupper(word[0]);
    bool flag_second = isupper(word[1]);
    if (!flag_first && flag_second) return false;

    for (int i = 2; i < word.size(); i++)
    {
        bool flag_cur = isupper(word[i]);
        if (flag_second != flag_cur) return false;
    }
    return true;
}
```

### 踩坑
![图片.png](https://pic.leetcode-cn.com/d81e38ffb3d7baeadddd7e7259b2ab8b639c87d473f6a0125f1061f678b92e3c-%E5%9B%BE%E7%89%87.png)
因为 `isupper()` 函数的返回值是整数而不是布尔，配合我的奇葩写法，再加上我本地 `Visual Studio` 和 `leetcode` 使用的编译器不同，精准的踩到了一个坑。  

我本地 `Visual Studio` 返回 0 和 1，`leetcode` 使用的编译器返回的是 0 和 256 。

![图片.png](https://pic.leetcode-cn.com/33bf67220fed95995819c264b9853b43ecc514695fc41733ed80004486fd0469-%E5%9B%BE%E7%89%87.png)

```C++ []
bool detectCapitalUse(string word)
{
    if (word.size() < 2) return true;
    bool flag_first = isupper(word[0]);
    cout << boolalpha << flag_first << endl;
    bool flag_second = isupper(word[1]);
    cout << boolalpha << flag_second << endl;
    if (!flag_first && flag_second)
    {
        cout << "false here: 0";
        return false;
    }
    for (int i = 2; i < word.size(); i++)
    {
        cout << "[" << i << "] = " << word[i] << "\t" << boolalpha << isupper(word[i]) << endl;
        if (flag_second != isupper(word[i]))
        {
            cout << "false here: " << i;
            return false;
        }
    }
    return true;
}
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

