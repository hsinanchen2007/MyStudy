vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> s;
		  vector<string> res;	 
		s['q'] =1;s['w']=1;s['e']=1;s['r']=1;s['t']=1;s['y']=1;s['u']=1;s['i']=1;s['o']=1;s['p']=1;
		s['a'] = 2;s['s'] = 2;s['d'] = 2;s['f'] = 2;s['g'] = 2;s['h'] = 2;s['j'] = 2;s['k'] = 2;s['l'] = 2;
		s['z'] = 3;s['x'] = 3;s['c'] = 3;s['v'] = 3;s['b'] = 3;s['n'] = 3;s['m'] = 3;//建立哈希表
		for(int i=0;i<words.size();i++){
			int  cnt =1;
			string temp =words[i];
			for(int j=0;j<temp.size();j++){
			if(temp[j]>='A'&&temp[j]<='Z'){
			temp[j]+=32;//转为小写
			}
			if(s[temp[j]]!=s[temp[0]]){
				cnt =-1;
			}
			if(cnt == -1)
		      break;
			}
			if(cnt == 1){
				res.push_back(words[i]);}//存入vector
		}
		return res;
    }