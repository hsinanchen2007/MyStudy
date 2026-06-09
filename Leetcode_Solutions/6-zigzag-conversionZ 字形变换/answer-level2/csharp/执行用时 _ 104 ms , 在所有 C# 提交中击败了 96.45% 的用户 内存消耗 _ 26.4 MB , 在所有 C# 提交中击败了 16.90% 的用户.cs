### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public string Convert(string s, int numRows) {
        int len = s.Length;
        List<char> chars = new List<char>();
        if(len <= numRows || numRows == 1){
            return s;
        }
        for(int i = 0;i <= (len - 1)/ (2 * numRows - 2);i++){
            chars.Add(s[i * (2 * numRows - 2)]);
        }
        for(int j = 1;j < numRows - 1;j++){
            chars.Add(s[j]);
            for(int i = 1;;i++){
                if(i * (2 * numRows - 2) - j < len){
                    chars.Add(s[i * (2 * numRows - 2) - j]);
                }
                else{
                    break;
                }
                if(i * (2 * numRows - 2) + j < len){
                    chars.Add(s[i * (2 * numRows - 2) + j]);
                }
                else{
                    break;
                }
            }
        }
        for(int i = 0;i <= (len - numRows)/ (2 * numRows - 2);i++){
            chars.Add(s[i * (2 * numRows - 2) + numRows - 1]);
        }
        return new string(chars.ToArray());
        
    }
}
```