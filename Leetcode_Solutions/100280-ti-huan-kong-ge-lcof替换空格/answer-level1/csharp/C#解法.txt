### 解题思路1
直接调用现成类库

### 代码

```csharp
public class Solution {
     public string ReplaceSpace(string s) {
         if(s == null)
         {
             return null;
         }
         return s.Replace(" ", "%20");
        
     }

}
```

### 解题思路2
循环

### 代码

```csharp
public class Solution {
    public string ReplaceSpace(string s) {
        if(s == null)
        {
            return null;
        }
        var array = s.ToCharArray();
        StringBuilder sb = new StringBuilder();
        foreach(var item in array)
        {
            if(item == ' ')
            {
                sb.Append("%20");
            }else{
                sb.Append(item);
            }
        }
        
        return sb.ToString();
    } 
}
```