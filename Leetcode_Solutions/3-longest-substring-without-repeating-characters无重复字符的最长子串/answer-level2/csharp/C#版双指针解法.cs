
执行用时 : 128 ms, 在Longest Substring Without Repeating Characters的C#提交中击败了96.18% 的用户
内存消耗 : 23.6 MB, 在Longest Substring Without Repeating Characters的C#提交中击败了39.86% 的用户
```
public int LengthOfLongestSubstring(string s)
    {
        int length = 0;//计算结果
        Dictionary<char, int> dic = new Dictionary<char, int>();//一个字典储存不重复的字符和他们的位置
        int point1 = 0, point2 = 0;//定义双指针
        while (point2 < s.Length)
        {
            //当前字符已经存在
            if (dic.ContainsKey(s[point2]))
            {
                /* 最关键的一步,为了保证[point1,point2]不重复,每次遇到重复字符s[point2]时,我们让point1走到上一个s[point2]+1的位置,保证[point1,point2]内不重复.
                 * 但是在"abba"的测试用例,走到s[3]时,我们发现point1居然回退了,这是不允许的
                 * 所以我们加了一个限制条件 只允许point1向前走 不可以回退
                 */
                point1 = dic[s[point2]] + 1 > point1 ? dic[s[point2]] + 1 : point1;
                //将索引替换成本次point2新的index,否则又会造成point1回退
                dic[s[point2]] = point2;
            }
            else
            {
                dic.Add(s[point2], point2);//不重复的字符 直接加入到字典中
            }
            length = length > point2 - point1 + 1 ? length : point2 - point1 + 1;//算一下本次循环后,双指针之间的长度是否超过了之前的最大长度
            point2++;//point2指针向后走
        }
        return length;
    }
```