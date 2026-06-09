map<int,int> myMap;
void DFS(vector<Employee*> employees,int id,int& res,map<int,int>& myMap){
    int posi=myMap.find(id)->second;
    res+=employees[posi]->importance;
    if(employees[posi]->subordinates.size()==0) return; 
    for(int i=0;i<employees[posi]->subordinates.size();i++){
        DFS(employees,employees[posi]->subordinates[i],res,myMap);
    }
}
int getImportance(vector<Employee*> employees, int id) {
    int res=0;
    for(int i=0;i<employees.size();i++){
       myMap[employees[i]->id]=i;
    }
    DFS(employees,id,res,myMap);
    return res;
    
}