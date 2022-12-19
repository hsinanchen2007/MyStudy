```
class Solution {
public:
    int numTrees(int n) {
    	if(n<=0) return 0;
    	
    	int arr[100];
    	memset(arr,0,sizeof(arr));
    	arr[0] = arr[1] = 1;
    	
    	//计算由i个数字组成搜索树有多少种可能 必定由 0 ~ i-1 可以得到该结果 
        for(int i=1;i<=n;i++){
        	int cal = 0;
        	//选中j作为当前节点，则左边的数字作为左子树，右边的数字作为右子树 
        	for(int j=1;j<=i;j++){
        		int left_count = max(j - 1, 1);
        		int right_count = max(i - j, 1);
        		//左子树可能的组合种数 * 右子树可能的组合种数 
        		cal += arr[left_count] * arr[right_count];
			}
			arr[i] = cal;
		}
		return arr[n];
    }
};
```
