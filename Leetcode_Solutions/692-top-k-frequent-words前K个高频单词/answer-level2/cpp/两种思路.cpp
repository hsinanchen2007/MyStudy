### 解题思路
其实就是两种思路:要不使用unordered_map先进行统计次数，然后使用sort排序，得出答案；要不就是使用堆（priprity_queue）来进行排序，得出答案。前者时间复杂度为+O(nlogn),后者为O(nlogk)，后者较优。
此处撰写解题思路

### 代码
```cpp
class Solution{
	public:
	//方法一
	
	static bool cmp(const pair<string,int> &a,const pair<string,int> &b){
		if(a.second!=b.second){
			return a.second>b.second;
		}
		else{
			return a.first<b.first;
		}
	}

	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> ans;
		if(words.size()==0){
			return ans;
		}

		unordered_map<string,int> m;
		for(int i=0;i<words.size();i++){
			m[words[i]]++;
		}

		vector<pair<string,int> > temp;
		unordered_map<string,int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			temp.push_back(make_pair(it->first,it->second));
		}

		sort(temp.begin(),temp.end(),cmp);

		for(int i=0;i<k;i++){
			ans.push_back(temp[i].first);
		}

		return ans;
	}
```

----

```cpp
class Solution {
public:
//方法二
    struct cmp{
        bool operator ()(const pair<string,int> &a,const pair<string,int> &b) const{
            if(a.second!=b.second){
               return a.second>b.second;
            }
            else{
               return a.first<b.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.size()==0){
            return vector<string>{};
        }

        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }

        vector<string> ans;
        priority_queue<pair<string,int>, vector<pair<string,int> > ,cmp> p;
        unordered_map<string,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            p.push(make_pair(it->first,it->second));
            if(p.size()>k){
                p.pop();
            }
          

           
        }
          
        for(int i=0;i<k;i++){
                ans.push_back(p.top().first);
                p.pop();
        }

        vector<string> ans1;
        for(int i=0;i<k;i++){
            ans1.push_back(ans[k-i-1]);
        }
            
    
        return ans1;

    }
};
```