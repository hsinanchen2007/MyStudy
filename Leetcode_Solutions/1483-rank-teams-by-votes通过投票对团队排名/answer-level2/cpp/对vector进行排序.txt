### 解题思路
本题的思路其实很简单，就是对vector进行排序。这里我们通过vector找到按顺位的数目，然后可以进行排序，不过需要注意一点的是，排序后，就成了乱序了，这个时候如何还原呢？
有两种方法：
- map构建映射，即map<string,vector<vector<int>>>
- vector<vector<int>>再扩展一位，方便计算。

所以，我们为了节省空间利用率，使用了vector<vector<int>>中多加一位的方法，用以标记字符。
这样sort之后，就不会丢失对应关系了。

sort的话，也是比较麻烦，如果不知道sort函数可以直接对vector<vector<int>>排序的话，这一步就会卡在这里。
所以，我们对其进行排序。
另外，其实不需要使用greater来进行顺序变换的。
只需要再输出的时候，逆向比较，就可以了。

### 代码

```cpp
class Solution {
public:
    //其实就是排序；
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> res(27,vector<int>(27,0));
        for(int i=0;i<votes.size();i++){
            for(int j=0;j<votes[i].size();j++){
                res[votes[i][j] - 'A'][j]++;
                //这一步保证了排序后，依然可以找到对应的字母
                res[votes[i][j] - 'A'].back() = 26 - (votes[i][j] - 'A');
            }
        }
        sort(res.begin(),res.end());
        int is_zero = false;
        string result;
        for(int i=res.size()-1;i>=0;i--){
            //这里和前面呼应，如果没有存入字符，则为0，可以减少很多运算量。
            if(res[i].back() != 0)
            {
                cout << i << endl;
                result += (26 - res[i].back() + 'A');
            }
        }
        return result;
    }
};
```