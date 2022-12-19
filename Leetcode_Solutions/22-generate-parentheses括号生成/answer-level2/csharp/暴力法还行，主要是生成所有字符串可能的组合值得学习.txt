### 解题思路
判断是否是合法的括号组合不需要用栈，用一个数值计数就可以了

### 代码

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        char[] str = new char[2*n];
        IList<string>res = new List<string>();
        int pos = 0;
        GenerateAll(str,res,pos);
        return res;
    }
    public void GenerateAll(char[] str,IList<string> res,int pos){
        if(pos == str.Length){
            if(Balance(str)){
                res.Add(new string(str));
            }
        }else{
            str[pos] = '(';
            GenerateAll(str,res,pos+1);
            str[pos] = ')';
            GenerateAll(str,res,pos+1);
        }
    }
    public bool Balance(char[] str){
        int balance = 0;
        foreach(char c in str){
            if(c == '('){
                balance++;
            }else{
                balance--;
            }
            if(balance<0){
                return false;
            }
        }
        return balance==0;
    }
}
```