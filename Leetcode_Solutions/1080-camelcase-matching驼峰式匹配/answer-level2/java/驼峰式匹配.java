### 方法：字符串匹配

#### 思路：
我们依次取出`quries`数组中需要查询的每个字符串，将它和`pattrn`进行匹配，并将每次匹配的结果加入结果数组中。

#### 算法：

对于一个带查询的字符串`query`和`pattrn`我们可以用如下的方式判断它们是否匹配
- 开始分别用两个指针`idx1`和`idx2`指向`query`和`pattrn`的头部。
- 判断两个指针所指向的字符是否相等，如果相等则同时后移
- 若不相等，则`idx1`的指针不断后移，直到走到`query`字符串末尾或和`idx2`指向的字符相等。注意根据题意我们只能插入小写字母，故`idx1`后移的过程中若遇到不匹配大写字母，则立即返回`false`。
- 当指针`idx1`或`idx2`走到字符串的末尾时退出循环，这时我们要判断`idx2`是否走到了`pattrn`字符串的末尾，如果不是，说明我们还有剩余字符未成功匹配,返回`false`。同时我也要判断`query`中剩余的字符中是否全是小写字母，若不是返回`false`。

![WX20190821-174256@2x.png](https://pic.leetcode-cn.com/1ac47ef52e676f3dff42d6f2789abaa7cc89e07d6ff845f9d7d6c5924c7480b8-WX20190821-174256@2x.png)



```java []
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for (String query : queries) 
            ans.add(isMatch(query, pattern));
        return ans;
        
    }
    private boolean isMatch(String query, String pattern) {
        int idx1 = 0, idx2 = 0, n1 = query.length(), n2 = pattern.length();
        while (idx1 < n1 && idx2 < n2){
            char ch1 = query.charAt(idx1), ch2 = pattern.charAt(idx2);
            if (ch1 == ch2) {
                idx1++;idx2++;
            } else {
                if (ch1 >= 'A' && ch1 <= 'Z') return false;
                idx1++;
            }
        }
        if (idx2 != n2) return false;
        while (idx1 < n1) {
            char ch1 = query.charAt(idx1++);
            if (ch1 >= 'A' && ch1 <= 'Z') return false;
        }
        return true;
    }
}
```
#### 复杂度分析：
设$quries$数组长度为$N$，字符串总长度为$M$，$pattren$的长度为$K$
- 时间复杂度：$O(M+N*K)$
- 空间复杂度：$O(1)$ 不包含返回值数组所占用空间
