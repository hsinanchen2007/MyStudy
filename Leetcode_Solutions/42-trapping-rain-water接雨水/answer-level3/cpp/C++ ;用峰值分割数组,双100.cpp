**解题思路:**

- 定义返回值`res`= 0
- 遍历数组以寻找峰值索引top
- 在左侧规定一个`tmp`作为边缘峰值索引,用参数`i`按照下列规定遍历区间`(tmp,top)`:
    1. 若`s[tmp] > s[i]`,则 res += `s[tmp] - s[i]`
    2. 不满足`条件1`,则更新`tmp = i`
- 在右侧规定一个`tmp`作为边缘峰值索引,遍历区间`(top,tmp)`

```
class Solution {
public:
    int trap(vector<int>& s) {
        int res=0,top=0;
        for(int i=0;i<s.size();++i)
            if(s[i]>s[top])
                top=i;
        for(int tmp=0,i=tmp+1;i<top;++i)
            if(s[tmp]>s[i])
                res+=s[tmp]-s[i];
            else tmp=i;
        for(int tmp=s.size()-1,i=tmp-1;i>top;--i)
            if(s[tmp]>s[i])
                res+=s[tmp]-s[i];
            else tmp=i;
        return res;
    }
};
```
