![5.PNG](https://pic.leetcode-cn.com/fda7a3cc796b70ca4041c741bd8366ec4eae44c2007a175016b0cdda24adb9ad-5.PNG)

```
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> re(arr.size());
        int i,max=arr[arr.size()-1];
        int tmp;
        for(i=arr.size()-2;i>=0;i--){
        	tmp=arr[i];
        	re[i]=max;
        	if(tmp>max)
        		max=tmp;
		}
		re[re.size()-1]=-1;
		return re;
    }
};
```
