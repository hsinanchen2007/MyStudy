### 解题思路
将时间用h1 h2:m1 m2表示，则可以知道它们的取值范围为：

- h1 = 0,1时，h2 =  0-9；h1 = 2时，h2 = 0-3
- m1 = 0-5
- m2 = 0-9

分情况讨论

- 如果m2不是四个数中最大的数，则直接将m2替换为大于m2的最小的数即可
- 否则，需要考虑进位，即看m1
  - 如果存在大于m1且小于等于5的最小的那个数，则把m1替换为该数，m2替换为最小的数即可
  - 否则，需要继续考虑进位，即看h2
    - 如果存在大于h2的最小的那个数
      - 如果h1<2，则把h2替换为该数，m1m2替换为最小的数即可
      - 如果h1=2，
        - 如果这个数小于4，则把h2替换为该数，m1m2替换为最小的数即可
        - 否则，继续考虑进位，即看h1
    - 否则，继续考虑进位，即看h1
      - 如果存在大于h1且小于等于2的最小的那个数，则把h1替换为该数，h2m1m2替换为最小的数即可
      - 否则，相当于进入第二天，把h1h2m1m2都替换成最小的数


### 代码

```cpp
class Solution {
public:
    string nextClosestTime(string time) {
        char h1 = time[0];
        char h2 = time[1];
        char m1 = time[3];
        char m2 = time[4];
        vector<char> v = {h1, h2, m1, m2};
        sort(v.begin(), v.end());
        auto it = upper_bound(v.begin(), v.end(), m2);
        if(it != v.end()){
            m2 = *it;
        }
        else{
            it = upper_bound(v.begin(), v.end(), m1);
            if(it != v.end() && *it < '6'){
                m1 = *it;
                m2 = v[0];
            }
            else{
                it = upper_bound(v.begin(), v.end(), h2);
                if(it != v.end() && (h1<'2' || (h1=='2' && *it < '4'))){
                    h2 = *it;
                    m1 = m2 = v[0];
                }
                else{
                    it = upper_bound(v.begin(), v.end(), h1);
                    if(it != v.end() && *it <= '2'){
                        h1 = *it;
                        h2 = m1 = m2 = v[0];
                    }
                    else
                    	h1 = h2 = m1 = m2 = v[0];
                }
            }
        }
        string ans = "";
        ans += h1;
        ans += h2;
        ans += ':';
        ans += m1;
        ans += m2;
        return ans;
    }
};
```