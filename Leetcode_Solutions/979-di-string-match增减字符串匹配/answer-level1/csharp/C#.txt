### 解题思路
和转成chararray用foreach效率差不多
### 代码

```csharp
public class Solution {
    public int[] DiStringMatch(string S) {
        int left = 0;
        int len = S.Length;
        int right = len;
        var res = new int[len+1];
        for(int i = 0;i<len;i++){
            if(S[i]=='I'){
                res[i]=left;
                left++;
            }else{
                res[i]=right;
                right--;
            }
        }
        res[len]=left;
        return res;
    }
}
```