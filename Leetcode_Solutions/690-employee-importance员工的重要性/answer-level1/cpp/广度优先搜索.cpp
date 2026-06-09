```
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum=0;
		queue<Employee*> que;
		int length;
		//vector<int> suborid;

		for(int i=0;i<employees.size();++i){
			if(employees[i]->id==id){que.push(employees[i]);break;}//找出值为id的领导及其下属
		}

		while(que.size()){
			length = que.size();
			for(int i=0;i<length;++i){
				sum+=que.front()->importance;
				while(que.front()->subordinates.size()){
					for(int j=0;j<employees.size();++j){
						if(employees[j]->id==que.front()->subordinates[0]){que.push(employees[j]);
						que.front()->subordinates.erase(que.front()->subordinates.begin()+0);break;}
					}
				
				}
				que.pop();
				
			}
		
		}
		return sum;
    }
};
```
