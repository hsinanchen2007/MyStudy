![38. 外观数列 - 力扣（LeetCode）.png](https://pic.leetcode-cn.com/e6b01c8acba51d181473e081d9b533b23ff07bb4ae069839744971b87cec3ecf-38.%20%E5%A4%96%E8%A7%82%E6%95%B0%E5%88%97%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89.png)

```
`class Solution {
public:
    string countAndSay(int n) 
    {

        return qaq(n);
    }

    string qaq(int n)
    {
        if (n == 1)
            return "1";
        int i = 1;
        string _n1 = qaq(n - 1);
        string::iterator p = _n1.begin();
        string s="";
        while (p != _n1.end())
        {       
            if ((p != _n1.end()-1) && (*p == *(p + 1)))  //判断多（i）个相同的数字
            {
                i = 1;
                while ((p != _n1.end()-1) && (*p == *(p + 1)))
                {
                    p++;
                    i++;
                }
                s.push_back(i+48);
                s.push_back(*p);
                p++;
                continue;
            }
            s.push_back('1');   //如果没有相同的数字就是1个
            s.push_back(*p);
            p++;
        }
        return s;
    }

};`
```


