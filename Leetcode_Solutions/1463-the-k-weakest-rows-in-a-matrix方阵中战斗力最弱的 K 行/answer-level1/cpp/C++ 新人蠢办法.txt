struct des{
    int data;
    int num;
};
//构造一个数据结构，data用来存储军人的值，num用来存储下标；
bool cmp(des a, des b){
    if(a.data!=b.data)  return a.data<b.data;
    else    return a.num<b.num;
}
//比较函数，保证按照题目正确排序；
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        const int N = mat.size();
        des ans[N];
        for(int i=0;i!=mat.size();i++){
            int x=0;
            for(int j=0;j!=n;j++){
                if(mat[i][j]==0)
                    break;
                else
                    x += mat[i][j];
            }
            ans[i].num = i;
            ans[i].data = x;    //该循环将值逐个输入数组中；
        }
        sort(ans,ans+N,cmp);
        vector<int> ans1;
        for(int i=0;i!=k;i++)
            ans1.push_back(ans[i].num);
        return ans1;
    }
};
/*
执行用时 :16 ms, 在所有 C++ 提交中击败了45.57%的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/