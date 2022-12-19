```
class Solution {
public:
//拼接成一个新的整型数字。。。不是数组和最大。。。。
//有以下几点需要注意的就是：注意需要进行裁剪，还有就是熟练掌握STL
//贪婪做法。。
//lexicographical_compare(v1.begin(),v1.end(),v2.begin(),v2.end())返回的是boolean值，从小到大排序的

    vector<int>max_ans(vector<int>&num,int k){
        int n=num.size();
      
        vector<int>res;
        int top=n-k;//表示的是最多可以删除的数字，因为至少需要保留k个数字。
        for(int i=0;i<n;i++){
            while(!res.empty()&&num[i]>res.back()&&top>0){
                top--;
                res.pop_back();
            }
            res.push_back(num[i]);
        }
        res.resize(k);//因为最终的数字可能是大于k个的，所以一定要进行剪切
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<int>ans;
        for(int i=0;i<=k;i++){
            int j=k-i;
            if(i>m||j>n)continue;//注意这个过滤条件不能没有，否则会出错。。。
            
            vector<int>temp;
            vector<int>temp1=max_ans(nums1,i);
            vector<int>temp2=max_ans(nums2,j);
            //归并得到一个更大的数字
            auto s1=temp1.begin();
            auto e1=temp1.end();
            auto s2=temp2.begin();
            auto e2=temp2.end();
            
            while(s1!=e1||s2!=e2){
                temp.push_back(lexicographical_compare(s1,e1,s2,e2)?*s2++:*s1++);
            }
            ans=lexicographical_compare(temp.begin(),temp.end(),ans.begin(),ans.end())?ans:temp;//返回一个更大的数字
        }
        return ans;
    }
};
```
