先排序得到最小的序列，再利用递归，从后往前交换元素得到下一个排列。
```
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        sort(s.begin(),s.end());
        find_permutations(s,0,s.size(),res);
        return res;
    }
    void find_permutations(string s,int left,int right,vector<string> &res){
        if(left==right) res.push_back(s);
        else{
            for(int i=left;i<right;++i){
                if(i>left && s[i]==s[left]) continue;   // 相同元素不需要交换
                swap(s[i],s[left]);
                find_permutations(s,left+1,right,res);
            }
        }
    }
};
```
