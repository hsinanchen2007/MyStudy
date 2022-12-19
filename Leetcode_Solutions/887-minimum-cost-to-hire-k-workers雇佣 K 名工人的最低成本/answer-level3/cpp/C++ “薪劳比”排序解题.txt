**解题关键**：假定某位工人拿到最低期望工资，其“薪劳比”为WQ，那么该工作组中，只能存在（薪劳比[i] < WQ）的工人，且工人“质量”尽量低

**解题工具**：二维向量、Sort函数、优先队列

**源码**
```c++ []
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {

    vector<vector<double>>workers(quality.size(), { 0.0,0.0 });
    for (int i = 0; i < (int)workers.size(); i++) {
        workers[i][0] = double(wage[i]) / quality[i];
        workers[i][1] = double(quality[i]);
    }
    sort(workers.begin(), workers.end(), [](vector<double>a, vector<double>b){ return a[0] < b[0]; });

    double res = DBL_MAX;
    double q_sum = 0.0;	
    priority_queue<double>queue;
    for (auto worker : workers) {
        q_sum += worker[1];
        queue.push(worker[1]);
        if (queue.size() == K) {
            res = min(res, q_sum*worker[0]);
            q_sum -= queue.top(); queue.pop();
        }
    }
    return res;
}
```

