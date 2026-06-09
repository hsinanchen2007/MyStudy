### 解题思路
题目写的太绕了，读题读了很久；
真实题意是：限制条件是有h篇文章至少引用了h次,你要找这个h的最大值

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()){
            return 0;
        }
        sort(citations.begin(), citations.end());

        int H = 0;
        int right = citations.back();

        for (int i = 0; i <= right;i++){
            int count = 0;
            for(auto citation:citations){
                if(citation>=i){
                    count++;
                }
            }

            if(count >= i){
                H = max(H,i);
            }
        }

        return H;
    }
};
```