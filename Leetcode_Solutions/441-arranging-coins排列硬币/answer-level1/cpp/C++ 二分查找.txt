参考二分搜索模板 [leetcode35号问题解析](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)

```C++
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while(left < right){
        	int mid = left + (right - left + 1) / 2;  //取右中位数

        	if(((1+mid))*mid/2 > n){ ////先排除中位数
        		right = mid - 1;
        	} else{
        		left = mid;
        	}
        }
        return left;
    }
};
```

