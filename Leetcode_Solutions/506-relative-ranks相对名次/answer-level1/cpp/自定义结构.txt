```
struct Node{
	int id;
	int score;
	Node(int a,int b){
		id=a;
		score=b;
	}
};
const bool com(Node &a,Node &b){
	return a.score>b.score;
}
class Solution {
public:
	string change(int x){//将数字转为字符串 
		string s;
		while(x){
			s=(char)('0'+x%10)+s;
			x/=10;
		}
		return s;
	}
    vector<string> findRelativeRanks(vector<int>& nums) {
    	vector<Node> tmp;
    	int n=nums.size();
    	for(int i=0;i<n;i++)
    		tmp.push_back(Node(i,nums[i]));
    	sort(tmp.begin(),tmp.end(),com);
    	vector<string> re(n);
    	for(int i=0;i<n;i++){
    		if(i==0)
    			re[tmp[i].id]="Gold Medal";
    		else if(i==1)
    			re[tmp[i].id]="Silver Medal";
    		else if(i==2)
    			re[tmp[i].id]="Bronze Medal";
    		else
    			re[tmp[i].id]=change(i+1);
		}
    	return re;
    }
};
```
