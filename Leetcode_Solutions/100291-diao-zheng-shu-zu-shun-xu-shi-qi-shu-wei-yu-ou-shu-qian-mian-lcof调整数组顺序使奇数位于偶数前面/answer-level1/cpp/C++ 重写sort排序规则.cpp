该题目可转化为，在排序规则中，偶数比奇数大，因此可重写sort排序规则，直接用sort函数即可解答。
```
class Solution {
public:
 static bool cmp(int a,int b){
	if(b%2==0&&a%2!=0)return true;
	return false;
}
vector<int> exchange(vector<int>& nums) {
     sort(nums.begin(),nums.end(),cmp);
	 //for(auto x:nums)cout<<x<<endl;
	 return nums;
}
};
```
