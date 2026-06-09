int getImportance(vector<Employee*> employees, int id) {

	if (employees.size() == 0) return 0;
	unordered_map<int, int>map;
	for (int i = 0; i < employees.size(); i++) {
		map[employees[i]->id] = i;
	}
	int equal = 0;
	queue<int>qe;
	qe.push(map[id]);
	
	while (!qe.empty()){
		auto element = qe.front();
		equal += employees[element]->importance;
		qe.pop();
		if (employees[element]->subordinates.size() != 0) {
			for (auto p : employees[element]->subordinates)
				qe.push(map[p]);
		}
	}
	return equal;
}