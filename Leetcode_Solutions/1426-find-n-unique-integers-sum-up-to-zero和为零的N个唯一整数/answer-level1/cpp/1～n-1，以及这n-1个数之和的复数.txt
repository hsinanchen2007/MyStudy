![image.png](https://pic.leetcode-cn.com/0719d6e1eb2d119960e0024e5a108b58898ecf94b854d0a7660944e4a4af7be2-image.png)

```
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> re;
        int sum=0;
        for(int i=1;i<=n-1;i++){
        	sum+=i;
        	re.push_back(i);
		}
		re.push_back(-1*sum);
		return re;
    }
};
```
