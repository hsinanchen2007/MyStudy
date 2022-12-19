### 解题思路
![2020-04-02 133829.png](https://pic.leetcode-cn.com/db86f9fb3008ea6abd8cae7dd6461660011e9c319c83c5248def99b42fa65673-2020-04-02%20133829.png)

1.判断字符串a,b是否需要补位。初始化一个进位标志默认为0
2.从后往前遍历，利用ASCII码将字符转换为数字进行相加
3.先将结果除以2更新进位标志，然后对结果取余操作并转换为字符
4.遍历结束后，对进位标志进行判断，如果进位标志值为1，则在字符开始位置前插入1

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int aSize = a.size();
	    int bSize = b.size();
	    aSize < bSize ? a.insert(0, bSize - aSize, '0') : b.insert(0, aSize - bSize, '0');
	    int flag = 0;
	    for (int i = a.size() - 1; i >= 0;i--)
	    {
		    a[i] = a[i] -'0'+ b[i]-'0' + flag;
            flag=a[i]/2;
            a[i]=a[i]%2+'0';
	    }
	    if (flag == 1)
		    a.insert(0, "1");
	    return a;
    }
};
```