**思路**：首先找到要计算重要性员工 的id，id 进辅助队列并记录其重要性，然后该员工下属的 id 进队列，该员工的 id 出队列，之后再找到下属的 id 并记录重要性，重复上述步棸，直至无下属。
**C++ 版代码：**
```
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
    int sum = 0;            // 记录重要性变量
	queue<int> number;      // 辅助队列
	number.push(id);        // 员工 id 进队列
	// 先找到需要求重要性员工的 id
	for(int i = 0; i < employees.size(); i++){
		if(id == employees[i]->id){

            //while(!number.empty()){
            //cout<<employees[i]->id<<" 的重要性为:"<<employees[i]->importance<<endl;
            sum += employees[i]->importance;    // 员工的重要性累加
            for(int j = 0; j < employees[i]->subordinates.size(); j++)
                number.push(employees[i]->subordinates[j]);  // 员工 i 下属的 id 进队列
            if(!number.empty()){
                number.pop();    // 如果队列不为空，队头（员工id）出队列
            }
            if(!number.empty()){
                // 如果队列不为空，队头
                id = number.front();
                i = -1;  // 每一个员工号都从头开始查找
            }


		}
	}
    return sum;
    }
};
```
**Java 版代码：**
```
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        int sum = 0;          // 存储所求员工重要性变量
		LinkedList<Integer> number = new LinkedList<Integer>();  // LinkedList 子类实现了 Queue（队列）接口，辅助队列变量
		number.offer(id);     // 将目标 id 添加到队列结尾，这里用的是队列操作，不是链表
		for(int i = 0; i < employees.size(); i++) {
			if(id == employees.get(i).id) {
				System.out.println(employees.get(i).importance);
				sum += employees.get(i).importance;
			
				// 目标 id 下属的 id 进队列
				if(employees.get(i).subordinates != null) {
					for(int j = 0; j < employees.get(i).subordinates.size(); j++) {
						number.offer(employees.get(i).subordinates.get(j));
					}
				}
				
				if(!number.isEmpty()) {
					number.poll();      // 找到并删除队头
				}
				if(!number.isEmpty()) {
					id = number.peek();  // 找到并但不删除队头
					i = -1;              // 每一个 id 都从第一个员工寻找
				}
			}
		}
	      
		return sum;    
    }
}
```

