![TIM截图20200302183134.png](https://pic.leetcode-cn.com/48ae2afc803cf90b15f83970d326c32be56156534c72be8a48d7412895fca055-TIM%E6%88%AA%E5%9B%BE20200302183134.png)
解题思路：每个结构体有两个变量，第一个是字母，第二个是得分，因为26为得分超出整型范围，所以用int数组表示。26位数组score[i]表示该字母在第i+1名的得票数。
用ascii码表示对应“参选字母”，统计完得票数以后再将实际参与字母放入vector中排序即可。
    struct P{
   char who;	
   int score[26]={0};
};

P a[26];

int Pcmp(P p1,P p2){
	for(int i=0;i<26;i++){
		if(p1.score[i]==p2.score[i])continue;
		if(p1.score[i]>p2.score[i])return 1;
		if(p1.score[i]<p2.score[i])return 2;
	}
	if(p1.who<p2.who)return 1;
	return 2;
}



string rankTeams(vector<string>& votes) {
	for(int i=0;i<26;i++){
		P p;
		p.who='A'+i;
		a[i]=p;
	}
	
    int m=votes.size(),n=votes[0].size();
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			a[votes[i][j]-'A'].score[j]++;
		}
	}
   
	vector<P> person;
	for(int i=0;i<26;i++){
        /*for(int k=0;k<26;k++){
           cout<<a[i].score[k];
        }
        cout<<endl;*/
		if(votes[0].find(a[i].who)<n)person.push_back(a[i]);
	}
	//for(auto x:person)cout<<x.who<<endl;
	int len=person.size();//cout<<len<<endl;
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
            if(Pcmp(person[j],person[j+1])==2){
				P t=person[j];
				person[j]=person[j+1];
				person[j+1]=t;
            }
		}
	}
   
	string ans="";
	for(int i=0;i<len;i++){
		ans+=person[i].who;
	}
	
	
	
	return ans;
}