### 解题思路
跟语法没关，注意不包含自除数0代表一旦有0那么就不是自除数
### 代码

```csharp
public class Solution {
    public IList<int> SelfDividingNumbers(int left, int right) {
        var res = new List<int>(0);
           for(int i = left;i<right+1;i++){
                   var tmp = i;
                   var flag =true;
                   while(tmp!=0){
                           if(tmp%10==0){
                                   flag=false;
                                   break;
                           }
                           if(i%(tmp%10)!=0){
                                   flag = false;
                                   break;
                           }
                           tmp/=10;
                   }
                   if(flag) res.Add(i);
           }
            return res;
    }
}
```