和官方的方法二类似，不过这里用矢量完成插入，排序，而priority_queue用的应该是二叉树，所以速度慢一些。
直接用priority_queue更好，当然快排更快。
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec;
        if(!k) return vec;
        vec.push_back(arr[0]);
        for(auto x=arr.begin()+1;x<arr.end();++x){
            int flag=0;
            if(vec.empty()){
                vec.push_back(*x);
                continue;
            }
            for(auto it=vec.begin();it<vec.end();++it){
                if(*x<*it){
                    vec.insert(it,*x);
                    flag=1;
                    break;
                }
            }
            if(!flag) vec.push_back(*x);
            if(vec.size()>k) vec.pop_back();
        }
        return vec;
    }
};
```
