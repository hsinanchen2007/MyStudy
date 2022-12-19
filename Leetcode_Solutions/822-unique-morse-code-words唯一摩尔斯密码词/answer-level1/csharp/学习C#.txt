### 解题思路
比较想像python一样有一个Set来管理这个，而且没有像python一样可以一行处理字典里是否有这个key，如果没有赋值为0的函数么？
[@mantgh](/u/mantgh/)感谢大神，基本罗列了跟我的思路比较相符合的C#代码
定义省事小技巧`var tt = new Dictionary<string,int>();`
string 转 char数组`w.ToCharArray()`
StringBuilder 跟java一样，但是不要忘了`ToString()`
字典是否存在一个key的判断`dict.ContainsKey(key)`
感觉还可以判断value 的样子
可以直接用`dict.Count`来获得dict大小
### 代码

```csharp
public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
       string[] dic =new string[26] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
            var dict=new Dictionary<string,int>();
            foreach(string w in words){
                    char[] tmp = w.ToCharArray();
                    var tt = new StringBuilder();
                    foreach(char t in tmp){
                            tt.Append(dic[t-'a']);
                    }
                    var stt = tt.ToString();
                    if(!dict.ContainsKey(stt)) dict[stt]=0;
            }
                return dict.Count;
    }
}
```