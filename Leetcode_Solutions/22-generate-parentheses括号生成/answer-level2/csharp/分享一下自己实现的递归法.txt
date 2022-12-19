### 解题思路
斗胆分享一下自己实现的递归法

### 代码

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        List<string> result = new List<string>();
        if (n == 0){
            result.Add("");
            return result;
        }
        if (n == 1){
            result.Add("()");
            return result;
        }
        //取一对括号出来，根据这对括号里面有几对括号来遍历
        //改进,怎么解决(()())的情况
        for(int i = 1; i <= n; i++){
            //生成前缀
            List<string> pre = GenerateParenthesis(i-1).ToList();;
            //生成后缀
            List<string> sur = GenerateParenthesis(n-i).ToList();
            for(int j = 0; j < pre.Count; j++){
                for(int k = 0; k < sur.Count; k++){
                    result.Add("(" + pre[j] + ")" + sur[k]);
                }
            }
        }
        return result.ToList();
    }
}
```