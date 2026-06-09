### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
            //思路有很多
            //比如用哈希表，key代表nums[i]的值 value代表出现次数，最后只要找出value=1的那个i就可
            //也可以排序数组，比较数的前后是否一致
            Hashtable ht = new Hashtable();
            for(int i=0;i<nums.Length;i++)
            {
                if(ht.ContainsKey(nums[i]))
                {
                      ht[nums[i]] =(int)ht[nums[i]] +1;
                }
                else
                {
                    ht.Add(nums[i], 1);
                }
            }
            foreach(int key in ht.Keys)
            {
                if((int)ht[key]==1)
                {
                    return key;
                }
            }
            return -1;
    }
}
```