### 思路
1. 模拟

### 答题
```C++ []
int magicalString(int n)
{
    if (n < 1) return 0;
        
    int ans = 1;
    queue<int> que;
    que.push(2);
    int i = 3;
    int num = 2;
    //cout << 1 << "," << 2 << "," << 2 << ",";
    while (i < n)
    {
        num = (num == 1) ? 2 : 1;
            
        auto q = que.front();
        que.pop();

        if (q == 2)
        {
            que.push(num);
            i++;
            ans += (num == 1);
            //cout << num << ",";
        }
        if (i < n)
        {
            que.push(num);
            i++;
            ans += (num == 1);
            //cout << num << ",";
        }
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

