没什么好说的，就是实现一遍kmp算法，百度找了一圈，没靠谱的，自己翻以前的教材重新学习了一下，连教材上都一堆错误，最后自己悟了一下，过了。
关键点在于next数组的生成，next[0] = -1,next[1] = 0，这两个是固定的，并且在匹配时找到next[0]，即next值为负时表示当前没有任何可重复利用的部分，应该直接令i++,j=0（由于j==-1，j=0和j++是一样的，所以某些实现里没有单独用一个if来判断，而是把这个条件跟前面的if合到一起了，这一点比较迷惑人），很多实现里next[0] = next[1] = 0，这是错误的。
另外就是next数组的理解了，一句话，next[i]的含义应该是找到最大的k，满足pattern[0:k] == pattern[i-1-k:i-1]，但是使用普通匹配方法复杂度会达到O(n^2)，所以要利用已知的next信息。
```
public class Solution{
    public int StrStr(string haystack, string needle){
        if (needle == "")
            return 0;
        if (haystack == "")
            return -1;

        if (needle.Length > haystack.Length)
            return -1;

        int i, j;

        if (needle.Length == 1){
            for (i = 0; i < haystack.Length; i++)
                if (haystack[i] == needle[0])
                    return i;
                return -1;
        }

        int[] next = GetNext(needle);

        i = 0;
        j = 0;

        while (i < haystack.Length && j < needle.Length){
            if (haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }
            if (j == -1){
                i++;
                j = 0;
            }
        }

        if (j == needle.Length)
            return i - needle.Length;
        return -1;
    }

    int[] GetNext(string p){
        int[] next = new int[p.Length];
        next[0] = -1;
        next[1] = 0;
        int i = 2;
        while (i < p.Length){
            if (p[i - 1] == p[next[i - 1]]){
                next[i] = next[i - 1] + 1;
            }else{
                int k = i - 1;
                while (next[k] >= 0 && p[i - 1] != p[next[k]])
                    k = next[k];
                next[i] = next[k] + 1;
            }
            i++;
        }
        return next;
    }
}
```
