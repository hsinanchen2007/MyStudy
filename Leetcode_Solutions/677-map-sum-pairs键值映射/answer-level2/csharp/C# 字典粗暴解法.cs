```
public class MapSum {

    /** Initialize your data structure here. */
    public MapSum() {

    }
    
    Dictionary<string, int> kv = new Dictionary<string, int>();

    public void Insert(string key, int val) {
        kv[key] = val;
    }
    
    public int Sum(string prefix) {
        int sum = 0;
        foreach (var item in kv)
        {
            if (item.Key.StartsWith(prefix))
            {
                sum += item.Value;
            }
        }

        return sum;
    }
}
```
