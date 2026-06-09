### 执行用时：0ms
乍一看以为是字符串排序，但其实不需要我们排序，仅需要判断是否有序。
新的排序依据是给定的字典序，用一个哈希表记录每个字母的排名（或称之为优先级），这个哈希表就是新的字典序。
哈希表用大小为26的int[]数组，然后开始检查是否有序。
从左到右，每一前一后两个单词比较一次，在每次比较中，又对两个单词进行逐字母的比较：如果有序，跳过当前比较，开始后两个单词的比较；如果乱序，返回false；如果相等，则比较两个单词的下一个字母。同时，如果后面的单词先扫描完，也是返回false。

时间复杂度：O(n*m)。n为单词的个数，m为较长单词的字母数。
空间复杂度：O(1)。只有26个小写字母，哈希表大小为常数。

### 代码

```java
class Solution {
    private int[] hash = new int[26];
    
    public boolean isAlienSorted(String[] words, String order) {
        char[] o = order.toCharArray();
        for(int i = 0; i < 26; i++)
            hash[o[i] - 'a'] = i;
        return isSorted(words);
    }
    private boolean isSorted(String[] w) {
        for(int i = 0; i < w.length - 1; i++)
        {
            char[] a = w[i].toCharArray();
            char[] b = w[i+1].toCharArray();
            for(int j = 0; j < a.length; j++)
            {
                if(j == b.length)   
                    return false;
                if(hash[a[j] - 'a'] < hash[b[j] - 'a'])
                    break;
                if(hash[a[j] - 'a'] == hash[b[j] - 'a'])
                    continue;
                if(hash[a[j] - 'a'] > hash[b[j] - 'a'])
                    return false;
            }
        }
        return true;
    }
}
```