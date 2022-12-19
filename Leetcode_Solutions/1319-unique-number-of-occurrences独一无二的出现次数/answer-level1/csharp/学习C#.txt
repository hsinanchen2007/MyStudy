C#的foreach感觉比for效率更高
C#的HashSet 对应python的set
C#的哈希表Dictionary跟C++的map很像
C#的每个函数都要大写就很烦
比如如果要知道数组的长度 `arr.Length`
```C#
public class Solution {
    public bool UniqueOccurrences(int[] arr) {
        var dict = new Dictionary<int,int>();
        foreach(var i in arr){
            if(!dict.ContainsKey(i))
                dict.Add(i,0);
            dict[i]++;
        }
        var hashSet = new HashSet<int>();
        foreach(var pair in dict){
            if(hashSet.Contains(pair.Value))
                return false;
            hashSet.Add(pair.Value);
        }
        return true;
    }
}
```

