Hashtable 牛逼！

```
public int[] TwoSum(int[] nums, int target)
{
    Hashtable hashtable = new Hashtable();
    for (int i = 0; i < nums.Length; ++i) {
        var wantNum = target - nums[i];
        if (hashtable.Contains(wantNum))
            return new int[] { Convert.ToInt32(hashtable[wantNum]), i };
        hashtable[nums[i]] = i;
    }
    return new int[] { -1, -1 };
}
```


