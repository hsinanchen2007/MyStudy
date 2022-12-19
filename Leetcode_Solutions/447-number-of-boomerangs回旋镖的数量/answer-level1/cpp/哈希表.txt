```
int numberOfBoomerangs(vector<vector<int>>& points) {
       
		int result = 0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> recoder;
			for (int j = 0; j < points.size(); j++) {
				if (i != j)
					recoder[pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)]++;
			}
			for (unordered_map<int, int>::iterator itr = recoder.begin(); itr != recoder.end(); itr++) {
				if(itr->second>1)
				 result += (itr->second)*(itr->second - 1);
			}
		}
		return result;
    }
```
