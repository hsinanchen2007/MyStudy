1. 经分析，第一行和最后一行间隔一个放置，中间行满放置。
2. 单列顺序从上到下，双列顺序从下到上，单列满，双列空。
3. 分组：两列一组，视为同样的规律，获得对应关系；
4. 临界点判断。

```
    string convert(string s, int numRows) {
    if(numRows==1)
        return s; 
    int num = 2 * numRows - 2;
	int n = s.size() / num;
	string result = s;
	int index =0,i,j;
	for (j = 0; j < numRows; j++){
		for (i = 0; i < n; i++){
			result[index++] = s[i * num + j];
			if (j != 0 && j != numRows - 1)
				result[index++] = s[(i+1) * num - j];
		}
		if ((i*num + j) < s.size()){
			result[index++] = s[i * num + j];
			if ((j != 0 && j != numRows - 1) && (i + 1) * num - j < s.size()){
				result[index++] = s[(i+1) * num - j];
			}
		}	
	}
	return result;
    }
```
