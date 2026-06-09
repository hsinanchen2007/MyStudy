### 解题思路
在运行第一编代码的时候没有考虑动态数组是怎么排列的
### 代码

```csharp
public class Solution {
    public int HammingDistance(int x, int y) {
        List<int> a = new List<int>(0);
        List<int> b = new List<int>(0);
            while(x!=0){
                    a.Add(x%2);
                    x/=2;
            }
            while(y!=0){
                    b.Add(y%2);
                    y/=2;
            }
        int l = Math.Max(a.Count,b.Count);
            int res=0;
            for(int i = 0;i<l;i++){
                    if(i<a.Count&&i<b.Count) {
                            if(a[i]!=b[i]) res++;
                            }
                    else if(i<a.Count){
                            if(a[i]!=0) res++;
                    }
                    else{
                            if(b[i]!=0) res++; 
                    }
            }
            return res;
    }
}
```