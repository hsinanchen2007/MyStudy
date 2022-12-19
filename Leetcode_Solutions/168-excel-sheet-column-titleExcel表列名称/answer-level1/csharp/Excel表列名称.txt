**思路：** 其实就是10进制数转换成26进制数，但是要特别注意这个26进制不是0-25而是1-26，需要对边界特别处理。
![e43137cbb4b4c96d90b6efb4ed5be56.jpg](https://pic.leetcode-cn.com/f31953455d8531ca5cc11f60145b2f00d0b9b27d91b2e7b282fc6f9deb82906b-e43137cbb4b4c96d90b6efb4ed5be56.jpg)



**代码：**
```
public string ConvertToTitle(int n)
        {
            StringBuilder sb = new StringBuilder();
            while (n > 0)
            {
                int reminder = n % 26;
                if (reminder == 0)
                {
                    reminder = 26;
                    n -= 1;
                }
                sb.Insert(0, (char)('A' + reminder - 1));
                n /= 26;
            }
            return sb.ToString();
        }
```
