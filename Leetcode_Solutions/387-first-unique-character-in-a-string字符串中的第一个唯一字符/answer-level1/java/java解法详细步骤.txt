### 解题思路
此处撰写解题思路
首先，我想计算出该字符串中每个字符重复的个数。
其次，我要找出重复次数为1的字符。
因为题目告诉我们全部为小写字母，小写字母共有26个，那如果我们定义一个长度为26的数组，a->z 每个小写单词对应 0->25 ，那么我就很容易知道每个字母重复的次数了。
int only[] = new int[26]
如何判断呢？
我们知道，字符减去字符得整数，那么
    for(int i = 0; i < s.length(); i++){
        only[s.charAt(i) - 'a']++;
    }
就可以解决这个问题
此时就得到了传进来的字符串中每个字母重复的次数
用同样的for循环，那么遍历这个26位数组的顺序也是一样的
    for(int i = 0; i < s.length(); i++){
        if(only[s.charAt(i) - 'a'] == 1)    //判断哪个字符的重复次数为 1
            return i;   //返回下标
    }
最后，如果没有，就返回 -1
### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        int only[] = new int[26];
        for(int i = 0; i < s.length(); i++){
            only[s.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(only[s.charAt(i) - 'a'] == 1)
                return i;
        }
        return -1;
    }
}
```