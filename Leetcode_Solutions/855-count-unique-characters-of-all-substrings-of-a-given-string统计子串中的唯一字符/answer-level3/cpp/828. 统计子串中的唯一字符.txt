### 解题思路
我觉得这种题有一种“**逆向思维**”。
你本来想求的是某个子序列中有多少个只出现一次的字母，也就是说：*先给定子序列，然后再去求单独的字母*。可是这种做法的时间复杂度一定是$O(n!)$，因为需要遍历所有的$n!$个子序列，一定会超时。
而这道题用到的思路是，我并不遍历所有子序列，而是看看每个字母在那些子序列中指出现了一次。那么思路就简单明了了，对于某个位置的字母，我搜它的左边，找到和它相同的字母索引；再搜右边，找到和它相同的字母索引，这样在这个范围内所有包含该字母的子序列个数，就是该位置字母对答案的贡献量。那么这种子序列个数该如何计算呢？这是这道题的第二个难点吧。具体看代码。

我最开始写的一版代码就很慢，原因是对于每个位置的字母我都找一遍它左右的范围，其实这步操作是很冗余的，因为每次找到的边界结果完全可以储存起来，供下一次使用。


### 代码
```改进后的 []
class Solution {
public:
    int uniqueLetterString(string s) {
        long ans(0);
        vector<int> prevLeft(26,-1);//注意这里初始化为-1
        vector<int> prevRight(26,s.size());//注意这里初始化为s.size()
        int *left = new int[s.size()];
        int *right = new int[s.size()];

        for(int i=0;i<s.size();i++){
            left[i] = prevLeft[s[i]-'A'];
            prevLeft[s[i]-'A'] = i;//把上次找到的相同字母的位置保存起来
        }
        for(int i=s.size()-1;i>=0;i--){
            right[i] = prevRight[s[i]-'A'];
            prevRight[s[i]-'A'] = i;
        }
        for(int i=0;i<s.size();i++)
            ans += (i-left[i])*(right[i]-i);//本题的第二个难点，假设从i起（含i）左边n个与它不同，右边m个与它不同，那么i对答案的贡献就是nxm。

        ans %= 1000000007;
        delete[] left;
        delete[] right;
        return ans;
    }
};
```
```慢速的 []
class Solution {
public:
    int uniqueLetterString(string s) {
        long ans  = 0;
        int left(0),right(0);
        for(int i = 0;i<s.size();i++){
            for(left = i-1;left>=0;left--){//对于每个位置的字母都找一遍其左右边界，带来大量冗余的工作。
                if(s[left] == s[i])
                    break;
            }
            left++;
            for(right = i+1;right<s.size();right++){
                if(s[right]==s[i])
                    break;
            }
            right--;
            left = i-left;
            right = right - i;
            ans += left + right + left*right + 1;
        }
        ans = ans%1000000007;
        return ans;
    }
};
```
