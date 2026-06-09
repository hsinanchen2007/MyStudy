### 解题思路
思路很简单 
1. 首先把字符串变成数组形式arr
2. 新建临时变量temp来存储最大字符串
3. 循环数组，对比temp中是否存在数组元素，如果存在，代表重复了，那么就需要删除temp中的重复元素 也就是截取字符串
4. 最后选择最大的就行！我这么做是为了能够清晰明了看到有多少个不重复的字符串
5. 采用C#编码来实现
### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string str) {
        if (str==null)
            {
                throw  new ArgumentNullException();
            } 
            var arr = str.ToCharArray();//转换成字符数组
            var num = new List<int>();//字符串不重复长度数组
            var temp = "";//临时数组
            for (int i = 0; i < arr.Length; i++)
            {
                //如果有代表重复了，需要截取
                if (temp.IndexOf(arr[i])>-1)
                {
                    num.Add(temp.Length);//增加
                    temp = temp.Substring(temp.IndexOf(arr[i])+1);
                }
                temp += arr[i];
            } 
            num.Add(temp.Length);//这个需要添加
            return num.Max(); 
    }
}
```