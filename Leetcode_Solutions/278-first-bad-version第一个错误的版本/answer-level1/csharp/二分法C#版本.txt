思路：


细节分析：


重点：
```
public class Solution : VersionControl {
    public int FirstBadVersion(int n) {
        if(n < 1){return 0;} 

        int start = 0;
        int end = n;

        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(IsBadVersion(mid))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        return end;
    }
}
```


