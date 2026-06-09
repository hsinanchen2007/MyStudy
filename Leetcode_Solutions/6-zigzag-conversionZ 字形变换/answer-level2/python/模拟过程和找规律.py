## 思路：

### 思路1：模拟过程

   Z字形，就是两种状态，一种垂直向下，还有一种斜向上

   控制好边界情况就可以了。

### 思路 2：找规律


![1555486964093.png](https://pic.leetcode-cn.com/3599a29d7d248062b64676d35f807e781148ae4d5c3feab1ae8f49857245d970-1555486964093.png){:width=340}
{:align=center}


![Snipaste_2019-05-07_15-58-37.png](https://pic.leetcode-cn.com/b2763c8bea5b37787b062fcab8d973080ab7040c73e1c9dc63eb9a911459ce33-Snipaste_2019-05-07_15-58-37.png){:width=300}
{:align=center}


如上图所示，我们发现规律：

1. 每一个Z字的首字母差，`numRows*2-2` 位置
2. 除去首尾两行，每个 Z 字有两个字母，索引号关系为，一个为 `i`，另一个为 `numsRows*2-2-i`


## 代码：

思路 1：

```Python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s:
            return ""
        if numRows == 1:return s
        s_Rows = [""] * numRows
        i  = 0
        n = len(s)
        while i < n:
            for j in range(numRows):
                if i < n:
                    s_Rows[j] += s[i]
                    i += 1
            for j in range(numRows-2,0,-1):
                if i < n:
                    s_Rows[j] += s[i]
                    i += 1
        return "".join(s_Rows)
```

思路 2：

```Python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s:
            return ""
        if numRows == 1:return s
        split_s_len = numRows * 2 - 2
        data = []
        n = len(s)
        
        for i in range(0, n,split_s_len):
            data.append(s[i:i+split_s_len])
        #print(data)
        res = ""
        for i in range(numRows):
            for tmp in data:
                if i < len(tmp):
                    if i == 0 or i == numRows-1:
                        res += tmp[i]
                    else:
                        res += tmp[i]
                        if split_s_len -i  < len(tmp):
                            res += tmp[split_s_len-i]
        return res
```
```Java []
class Solution {
    public String convert(String s, int numRows) {
        //字符串转化成数组
        char[] c = s.toCharArray();
        //创建字符串数组
        StringBuffer[] sb = new StringBuffer[numRows];
        for(int i = 0; i < sb.length; i++)
            sb[i] = new StringBuffer();
        int i = 0;
        int len = c.length;
        while(i < len){
            for(int idx = 0; idx < numRows && i < len; idx++)
                sb[idx].append(c[i++]);
            for(int idx = numRows - 2; idx >= 1 && i < len; idx--)
                sb[idx].append(c[i++]);
        }
        //拼接所有字符串
        for(int idx = 1;idx < numRows;idx++)
            sb[0].append(sb[idx]);
        return sb[0]oString();
    }
}
```

