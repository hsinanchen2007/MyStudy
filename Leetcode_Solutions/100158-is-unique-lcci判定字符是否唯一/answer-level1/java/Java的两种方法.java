解法一：直接利用String类型的indexOf方法：

```
class Solution {
    public boolean isUnique(String astr) {
        for(int i = 0; i < astr.length() - 1; i++)
        {
           if(astr.indexOf(astr.charAt(i), i+1) != -1)
           {
               return false;
           }
        }

        return true;
    }
```

解法二：双指针暴力循环

```
class Solution {
    public boolean isUnique(String astr) {
        boolean isSame = true;
        for(int i = 0; i < astr.length() - 1; i++)
        {
            for(int j = i + 1; j < astr.length(); j++)
            {
                if(astr.charAt(i) == astr.charAt(j))
                {
                    return false;
                }
            }
        }

        return isSame;
    }
}
```
