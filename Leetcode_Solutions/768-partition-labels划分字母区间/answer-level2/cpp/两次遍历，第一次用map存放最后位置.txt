### 解题思路
C++本身提供find_last_of的函数，但耗时较多。于是考虑O(N)的手动遍历一遍字符串S,将每个字符的位置存在一个map<char,int>中，字符为关键字，遍历结束，每个关键字对应的int值就是最后出现的位置。
两个指针用来划分区间，再度遍历，根据之前得到的最后位置来不断移动后面的指针。第一个区间记得+1。

### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> m;
        for(int i=0;i<S.size();i++){
            m[S[i]]=i;
        }
        vector<int> res;
        int e=0,s=0;
        for(int i=0;i<S.size();i++){
            int t=m[S[i]];
            if(t>e) e=t;
            if(i==e){
                res.push_back(e-s);
                s=e;
            }
        }
        res[0]++;
        return res;
    }
};
```