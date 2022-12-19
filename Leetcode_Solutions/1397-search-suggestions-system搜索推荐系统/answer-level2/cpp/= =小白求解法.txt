直接粗暴的思路：
一开始拿到这道题的时候，最先想到的就是直接上搜索方法。
两个数组，一个存结果，一个存上一次的搜索结果。 //结果只显示3个，但是可能搜到很多个
下一次搜索，继续字符串前缀搜索，若前缀搜索不到，则调用上一次搜索结果搜索。
废话不多说，直接上代码。
```
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<vector<string>> mid_ans;
        vector<string> temp1;
        vector<string> temp2;

        //一次前缀搜索
        sort(products.begin(),products.end());
        for(auto product: products){
            if(product[0]==searchWord[0]){
                temp1.push_back(product);
                if(temp2.size()<3){
                    temp2.push_back(product);
                }
            }
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        mid_ans.push_back(temp1);
        ans.push_back(temp2);

        //往后则基于上一次的搜索结果匹配即可
        for(int i=1; i<searchWord.length(); i++){
            vector<string> temp3;
            vector<string> temp4;
            for(auto anss: mid_ans[mid_ans.size()-1]){
                if(searchWord.substr(0,i+1) == anss.substr(0, i+1)){
                    temp3.push_back(anss);
                    if(temp4.size()<3){
                        temp4.push_back(anss);
                    }
                }
            }
            sort(temp3.begin(), temp3.end());
            sort(temp4.begin(), temp4.end());
            mid_ans.push_back(temp3);
            ans.push_back(temp4);
        }

        return ans;
    }
};
```
当然看着粗暴的思路，时间复杂度肯定也是爆炸。
**执行用时 :196 ms, 在所有 cpp 提交中击败了37.21%的用户
内存消耗 :95.9 MB, 在所有 cpp 提交中击败了100.00%的用户**
第一次写题解，下次再看看怎么优化吧。逃T T