```
//执行结果：通过显示详情 执行用时 4 ms, 在所有 C++ 提交中击败了98.15%的用户
//内存消耗 :10.5 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int len,max_len;
    vector<vector<int>> book;
    vector<int> counter;
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        len = books.size();max_len = shelf_width;
        book = books;
        counter.resize(len,-1);
        return dfs(0);
    }
    int dfs(int start) {
        if(start==len) return 0;
        if(counter[start]!=-1) return counter[start];
        int sum = 0;int max_height = 0;
        int mini = INT_MAX;
        for(int i=start;i<len;i++) {
            sum += book[i][0];
            if(sum>max_len) break;
            max_height = max(max_height,book[i][1]);
            mini = min(mini,max_height+dfs(i+1));
        }
        return counter[start] = mini;
    }
};
```
