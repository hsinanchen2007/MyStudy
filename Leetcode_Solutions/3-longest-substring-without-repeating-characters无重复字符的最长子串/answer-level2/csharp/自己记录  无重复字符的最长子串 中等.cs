### 解题思路
![无标题的笔记本-3.jpg](https://pic.leetcode-cn.com/174a491c82653b4a29b80fb8dc2dab3f0017752b542d484fd0016a551c3b9e67-%E6%97%A0%E6%A0%87%E9%A2%98%E7%9A%84%E7%AC%94%E8%AE%B0%E6%9C%AC-3.jpg)


这道题是没看答案自己做的，所以记录下这个笨方法的思路。

这个问题所有的情况都可以用图中的序列表示出来。α β代表重复的字符； 所有的解都可归纳为 r1 r2 r3 三种情况。
所以该题就是要比较 r1 r2 r3 的长短。
故可得到图片下方的三个等式 r1 r2的解是一样的  只有r3要判断末尾剩余不重复字符串的长度。

此解法 很慢。。。

执行用时 :
236 ms
, 在所有 C# 提交中击败了
19.76%
的用户
内存消耗 :
25.8 MB
, 在所有 C# 提交中击败了
5.28%
的用户
### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
         Dictionary<char, int> dic = new Dictionary<char, int>();
            int i = 0;   //从头遍历s中的字符
            int j = 0;   // 用来对结尾为非重复字符的后面的计数
            int between = 0;  // 两个重复字符之间的距离
            int result = 0;

            for (; i < s.Length; i++)     // 进入字符串循环
            {
                if (!dic.ContainsKey(s[i]))   // 判断是否为重复字符
                {
                    dic.Add(s[i], i);           // 没有就添加进dic
                    j++;                        // 对重复字符的后面的计数

                }
                else                            // 出现重复字符
                {
                    List<char> waitdelete = new List<char>();   
                    //定义一个待删除字符的list   因为出现重复字符时 位于该重复字符第一次出现的位置之前的字符不需要参加后续的重复检验 所以可以删除 
                    int former = 0;                 //计算该重复字符第一次出现的位置之前的长度
                    between = i - dic[s[i]];        //计算两个重复字符第之间的长度
                    j = 0;                         //j只是计算最后一个重复字符后面的长度 所以每次出现重复字符时重置为0
                    foreach (var node in dic)
                    {
                        if (node.Value < dic[s[i]])    // 遍历dic 找出位置比当前重复字符第一次出现小的字符 并计数
                        {
                            waitdelete.Add(node.Key);
                            former++;
                        }
                    }
                    foreach (var ele in waitdelete)
                    {
                        dic.Remove(ele);                 // 删除位于该重复字符第一次出现的位置之前的字符
                    }
                    dic[s[i]] = i;                  //把重复的字符dic中的value换成当前的i
                    result = Math.Max(result, former + between);
                }
            }

            result = j != 0 ? Math.Max(result, j + between) : result;   
            //如果j==0 则说明字符串是由重复字符作为结尾的， 若j！=0 则要判断当前的result 和 最后两个重复字符之间的距离 + 非重复字符的后面的字符数量 的大小
            result = result == 0 ? s.Length : result;
            return result;
         
            
    }
}
```


另一种方法： 
前一个想的太复杂，看了解题后发现这个思路很简单。
从一个字符开始标定头尾 然后将头尾之间的每一位与尾做对比
若有相同 将头节点移到此校验位的下一位 将现在的头尾长度和之前记录的长度取最大值来记录 在将尾后移一位 继续校验
若无相同 将现在的头尾长度和之前记录的长度取最大值来记录 在将尾后移一位 继续校验
运行到字符串末尾 即可找到最长字符串

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
 int head=0;
 int end=0;
 int cur=0;
 int max=0;
 while (end<s.Length)
{
    if (end>head)
    {
        cur=head;
        while (cur<end)
        {
            if(s[cur++]==s[end])
            {
                head=cur;
                break;
            }
        }
    }
    max=Math.Max(max,end-head+1);
    end++;
}
return max;



    }
}
执行用时 :
92 ms
, 在所有 C# 提交中击败了
90.94%
的用户
内存消耗 :
24.8 MB
, 在所有 C# 提交中击败了
63.02%
的用户