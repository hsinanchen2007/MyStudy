感觉sliding window这类题的共同点是有两个分别指向窗口起点终点的指针，终点指针是每次循环都更新，不同题目的区别在于起点指针的更新条件。

比如这道题起点指针的更新条件就是当前窗口内相同字母最多的值加k仍小于窗口长度时就更新起点指针。最长子序列那道题的起点更新条件就是新字符有没有在窗口内出现过。

起点指针的更新有的题是一次挪动一下，有的是一次可能挪动好几下（最长子序列）。

这道题比较不容易想到的几点是：
1. 只需要知道相同字母最多的值是多少，而不需要知道它是谁
2. 我最开始想的是用排序来统计出数量最多的字母，后来看别人的题解知道了只需要在每次终点指针移动时比较一下新加入的字母的数量和当前最大数量就可以了
3. 更新起点指针时，并不需要更新maxCount。因为在给定k时，maxCount是决定答案的唯一变量。只有maxCount变多时，ans才会变多。因为ans=maxCount+k。


```
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0;
        int ans = 0;
        int arr[26] = {0};
        for (int i=0,j=0;j<s.size();j++){
            arr[s[j]-'A'] ++;
            maxCount = max(maxCount,arr[s[j]-'A']);
            if(j-i+1-maxCount<=k){
                ans = max(ans,j-i+1);
            }
            else{
                arr[s[i]-'A']--;
                i++;
            }
        }
        return ans;
    }
};
```
