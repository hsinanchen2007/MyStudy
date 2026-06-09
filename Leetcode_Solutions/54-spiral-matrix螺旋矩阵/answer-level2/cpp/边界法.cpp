设置边界left, right, top, bottom, 每次转一圈，每圈从left-top->right-top, right-top->right-bottom, right-bottom->left-bottom, left-bottom->left-top。
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return {};
        int row=matrix.size(), col=matrix[0].size();
        vector<int> v(row*col,0);
        for(int l=0, r=col-1, t=0, b=row-1, c=0; l<=r && t<=b; ++l, --r, ++t, --b){
            for(int i=l; i<=r; v[c++]=matrix[t][i++]);
            for(int i=t+1; i<b; v[c++]=matrix[i++][r]);
            for(int i=r; i>=l && t<b; v[c++]=matrix[b][i--]);
            for(int i=b-1; i>t && l<r; v[c++]=matrix[i--][l]);
        }
        return v;
    }
};
```

![2019-06-20 11-17-21屏幕截图.png](https://pic.leetcode-cn.com/8a70acbcaf2be9e79e2b9987558aeef749aeb21349b03c324b6b0c0b99510096-2019-06-20%2011-17-21%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)