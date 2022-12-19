### 解题思路
1. 遍历整个 `products` 数组，找出与 `searchWord` 字符串第 1 个字符匹配的所有字符串，保存至数组 `match`。
2. 将 `match` 按照字典序排序。
3. 记 `temp = match`。如果 `temp` 中的元素个数大于 3，删除后面的元素，只保留 3 个元素。保存 `temp`。
4. 遍历 `match`，找出与 `searchWord` 字符串第 $i$ 个字符匹配的所有字符串，将其保存至数组 `match`。（$i = 2,...,match.length$）
5. 重复步骤 3 和 4，直至匹配完成 `searchWord` 中的所有字符。

### 代码
```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<string> match;
        
        // 遍历整个 products 数组，找出与 searchWord 字符串第 1 个字符匹配的所有字符串，保存至数组 match
        for(int i=0; i<products.size(); ++i)
        {
            if(products[i][0] == searchWord[0])
                match.push_back(products[i]);
        }

        sort(match.begin(), match.end()); // 将 `match` 按照字典序排序

        vector<string> temp = match;

        // 如果 temp 中的元素个数大于 3，只保留前 3 个元素
        while(temp.size() > 3)
            temp.pop_back();
        
        ans.push_back(temp); //保存 temp
        
        for(int i=1; i<searchWord.size(); ++i)
        {
            // 遍历 match，找出与 searchWord 字符串第 i 个字符匹配的所有字符串，保存至数组 match
            temp.clear();
            for(int k=0; k<match.size(); ++k)
            {
                if(match[k][i] == searchWord[i])
                    temp.push_back(match[k]);
            }
            match = temp;

            // 如果 temp 中的元素个数大于 3，只保留前 3 个元素
            while(temp.size() > 3)
                temp.pop_back();
            
            ans.push_back(temp);    //保存 temp
        }
        
        return ans;
    }
};
```

### 复杂度分析
时间复杂度：$O(L*N)$，其中 $L$ 表示 `searchWord` 字符串长度，$N$ 表示 `products` 数组的个数。
空间复杂度：$O(N)$。`match` 和 `temp`。
