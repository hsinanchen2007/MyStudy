### 解题思路
此处撰写解题思路
注意偶数情况
### 代码

```csharp
public class Solution {
    public void ReverseString(char[] s) {
        int n=s.Length;
        if(n!=0){
        for(int i=0;i<=(n-1)/2;i++){
            char temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
        }
        }
    }
}
```