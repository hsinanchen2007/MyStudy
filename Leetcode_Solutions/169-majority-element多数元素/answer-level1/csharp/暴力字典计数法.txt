### 解题思路
除了强行遍历以外的暴力解题方式  
声明一个字典对nums数组中的元素进行计数,然后对字典中的计数的数字进行排序,获取其中数量最多的value所对应的key,该key即为众数

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        var dic = new Dictionary<int,int>();
        foreach(var a in nums){
            if (dic.ContainsKey(a)){
                dic[a] = dic[a] + 1;
            }
            else{
                dic.Add(a,0);
            }
        }
        var maxkey = dic.Keys.Select(x => new { x, y = dic[x] }).OrderByDescending(x => x.y).First().x;
        return maxkey;
    }
}
```