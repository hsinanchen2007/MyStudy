### 解题思路
`ToCharArray()`挺好用的
### 代码

```csharp
public class Solution {
    public bool JudgeCircle(string moves) {
        char[] tmp  = moves.ToCharArray();
            int lr=0;
            int ud =0;
            foreach(char t in tmp){
                if(t =='U' ) ud++;
                    else if(t=='D') ud--;
                    else if(t=='L') lr++;
                    else lr--;
            }
            return (lr==0)&&(ud==0);
    }
}
```